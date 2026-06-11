#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,c;
ll D[33][33];
ll C[555][555];
ll A[3][33];

int main(){
    cin >> n >> c;
    for(ll i=1;i<=c;i++){
        for(ll j=1;j<=c;j++) cin >> D[i][j];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin >> C[i][j];
            if((i+j)%3==0) A[0][C[i][j]]++;
            else if((i+j)%3==1) A[1][C[i][j]]++;
            else if((i+j)%3==2) A[2][C[i][j]]++;
        }
    }
    ll res=1e18;
    for(ll i=1;i<=c;i++){
        for(ll j=1;j<=c;j++){
            if(j==i) continue;
            for(ll k=1;k<=c;k++){
                if(k==i||k==j) continue;
                else{
                    ll count=0;
                    for(ll l=1;l<=c;l++) count+=A[0][l]*D[l][i];
                    for(ll l=1;l<=c;l++) count+=A[1][l]*D[l][j];
                    for(ll l=1;l<=c;l++) count+=A[2][l]*D[l][k];
                    res=min(res,count);
                }
            }
        }
    }
    cout << res << endl;
}
