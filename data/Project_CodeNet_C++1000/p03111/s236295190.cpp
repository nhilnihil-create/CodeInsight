#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int res=1e9;
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    vector<int> t(n);
    rep(i,n) cin>>t[i];
    for(int i=0;i<(1<<16);i++){
        int A=0,B=0,C=0,tmp=i;
        int buf=0;
        rep(j,n){
            if(tmp%4==0){
                A+=t[j];
                tmp/=4;buf+=10;
            }else if(tmp%4==1){
                B+=t[j];
                tmp/=4;buf+=10;
            }else if(tmp%4==2){
                C+=t[j];
                tmp/=4;buf+=10;
            }else{
                tmp/=4;
            }
        }
        if(A==0||B==0||C==0)continue;
        buf+=abs(a-A)+abs(b-B)+abs(c-C)-30;
        chmin(res,buf);
    }
    cout<<res<<endl;
}