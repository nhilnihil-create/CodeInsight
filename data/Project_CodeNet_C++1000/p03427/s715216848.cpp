#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    ll res=0;
    bool jud=false;
    rep(i,s.size()){
        if(i==0){
            res+=(s[i]-'0');
            continue;
        }
        if(s[i]=='9'||jud)res+=9;
        else{
            res+=8;
            jud=true;
        }
    }
    cout<<res<<endl;
}