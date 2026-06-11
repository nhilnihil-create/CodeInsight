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
    vector<char> p,q;
    string s,t;
    cin>>s>>t;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        p.pb(c);
    }
    for(int i=0;i<t.length();i++){
        char c=t[i];
        q.pb(c);
    }
    sort(p.begin(),p.end());
    sort(q.rbegin(),q.rend());

    int ans=1;
    if(s.length()<t.length()){
        for(int i=0;i<s.length();i++){
            int a=p[i]-'a';
            int b=q[i]-'a';
            if(a>b){
                ans=0;
                break;
            }
            if(a<b){
                ans=1;
                break;
            }
        }
    }
    else{
        ans=0;
        for(int i=0;i<t.length();i++){
            int a=p[i]-'a';
            int b=q[i]-'a';
            if(a<b){
                ans=1;
                break;
            }
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
