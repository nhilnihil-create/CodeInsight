#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;

int main(){
    int N;
    ll x=-INF;
    ll buf;
    cin>>N;
    int F[N][10];
    int P[N][11];
    int count[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++){
                cin>>F[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<11;j++){
            cin>>P[i][j];
        }
    }
    for(int i=1;i<1024;i++){
        for(int m=0;m<N;m++){
        count[m]=0;
        }
        for(int j=0;j<10;j++){
            if(1&(i>>j)){
                for(int k=0;k<N;k++){
                    if(F[k][j]==1){
                        count[k]++;
                    }
                }
            }
        }
        for(int k=0;k<N;k++){
            if(k==0){
                buf=P[k][count[k]];
            }else{
                buf+=P[k][count[k]];
            }
        }
        if(buf>x){
            x=buf;
        }
    }
    cout<<x<<endl;
    return 0;
}