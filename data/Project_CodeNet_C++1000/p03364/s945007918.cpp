#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
const int mod=1e9+7;

int main(){
    int n;cin>>n;
    vector<string> s(n);
    int ans=0;
    rep(i,n)cin>>s[i];
    rep(i,n){
        bool flag=1;
        rep(j,n){
            if(!flag)break;
            rep(k,n){
                if(s[j][k]!=s[k][j]){
                    flag=0;break;
                }
            }
        }
        if(flag)ans+=n;
        string tmp=s[0];
        s.erase(s.begin());
        s.push_back(tmp);
    }
    cout<<ans<<endl;
}