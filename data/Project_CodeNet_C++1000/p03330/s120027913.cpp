#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int  n,c; cin >> n >> c;
    int d[c][c];
    rep(i,c)rep(j,c) cin >> d[i][j];
    int col[n][n];
    rep(i,n)rep(j,n) cin >> col[i][j];
    unordered_map<int,int> cc1,cc2,cc3;
    rep(i,n)rep(j,n){
        if((i+j)%3==0) cc1[col[i][j]]++;
        if((i+j)%3==1) cc2[col[i][j]]++;
        if((i+j)%3==2) cc3[col[i][j]]++;
    }
    //cout << cc1[3]+cc2[3]+cc3[3] << endl;

    int ans=INF;
    rep(i,c)rep(j,c)rep(k,c){
        if(i==j || i==k || j==k) continue;
        int tmp=0;
        rep(z,c){
            tmp+=d[z][i]*cc1[z+1];
            tmp+=d[z][j]*cc2[z+1];
            tmp+=d[z][k]*cc3[z+1];
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
