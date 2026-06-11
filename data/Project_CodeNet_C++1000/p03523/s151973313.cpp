#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    string s;
    cin>>s;
    string t="AKIHABARA";
    int z=0;
    if(s.size()>9){
        cout<<"NO"<<"\n";
        return 0;
    }
    rep(i,16){
        int B[4]={0};
        int p=i;
        rep(j,4){
            if(p%2) B[j]=1;
            p/=2;
        }
        int x=1,a=0;
        rep(j,9){
            if(j==0&&B[0]) continue;
            if(j==4&&B[1]) continue;
            if(j==6&&B[2]) continue;
            if(j==8&&B[3]) continue;
            if(t[j]!=s[a]) x=0;
            a++;
        }
        if(x){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    cout<<"\n";
}
