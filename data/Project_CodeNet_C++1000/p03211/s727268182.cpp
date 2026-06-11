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
    int res=1e+8;
    rep(i,s.size()-2){
        char a=s[i],b=s[i+1],c=s[i+2];
        int A=a-'0',B=b-'0',C=c-'0';
        int tmp=A*100+B*10+C;
        //cout<<tmp<<endl;
        chmin(res,abs(tmp-753));
    }
    cout<<res<<endl;
}