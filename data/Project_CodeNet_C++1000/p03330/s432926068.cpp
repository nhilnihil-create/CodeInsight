#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}

int a[4][44];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n,m;
    cin>>n>>m;
    int d[m][m],c[n][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
            c[i][j]--;
            a[(i+j)%3][c[i][j]]++;
        }
    }
    ll ans = 1e18;
    for(int i=0;i<m;i++){
        ll r1 = 0;
        for(int x=0;x<m;x++){
            if(x==i)continue;
            r1 += a[0][x]*d[x][i];
        }
        for(int j=0;j<m;j++){
            if(j == i) continue;
            ll r2 = 0;
            for(int x=0;x<m;x++){
                if(x == j)continue;
                r2 += a[1][x] * d[x][j];
            }
            for(int k=0;k<m;k++){
                if(k==i || k==j)continue;
                ll r3 = 0;
                for(int x=0;x<m;x++){
                    if(x == k)continue;
                    r3 += a[2][x] * d[x][k];
                }
                chmin(ans,r1+r2+r3);
            }
        }
    }
    cout << ans << endl;
    



}