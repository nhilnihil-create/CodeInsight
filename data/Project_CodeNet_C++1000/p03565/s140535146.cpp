#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t;
    cin>>s>>t;
    int m=t.length();
    int n=s.length();
    int ans=-1;
    for(int i=n-m;i>=0;i--){
        for(int j=i;j<i+m;j++){
            if(s[j]!=t[j-i] && s[j]!='?'){
                break;
            }
            if(j==i+m-1)
                ans=i;
        }
        if(ans!=-1){
            for(int j=i;j<i+m;j++){
                s[j]=t[j-i];
            }
            break;
        }
    }
    if(ans==-1)
        cout<<"UNRESTORABLE"<<endl;
    else{
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]='a';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
