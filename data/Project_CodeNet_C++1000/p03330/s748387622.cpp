#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll cl[3][33];



int main(){
    ll n,c;cin>>n>>c;
    ll d[33][33];
    rep(i,0,c)rep(j,0,c)cin>>d[i][j];
    rep(i,0,n){
        rep(j,0,n){
            ll C;cin>>C;
            if((i+j)%3==0)cl[0][C-1]++;
            else if((i+j)%3==1)cl[1][C-1]++;
            else if((i+j)%3==2)cl[2][C-1]++;
        }
    }
    ll MN=1e9,an;
    rep(i,0,c){
        rep(j,0,c){
            if(i==j)continue;
            rep(k,0,c){
                if(i==k||j==k)continue;
                an=0;
                rep(J,0,c)an+=d[J][i]*cl[0][J];
                rep(J,0,c)an+=d[J][j]*cl[1][J];
                rep(J,0,c)an+=d[J][k]*cl[2][J];
                MN=min(MN,an);
            }
        }
    }
    cout<<MN<<endl;
}
    







