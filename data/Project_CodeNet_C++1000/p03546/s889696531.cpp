#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


using Matrix = vector<vector<int>>;
Matrix M;
//グラフの距離を格納した２次元配列(隣接行列)
//M[u][v]はe=(u,v)のコスト

void warshall_floyd(int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                M[j][k] = min(M[j][k],M[j][i]+M[i][k]);
}


int main(){
    FIN;
    int h,w;
    cin >> h >> w;

    M = Matrix(10,vector<int>(10,0));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin >> M[i][j];
    

    warshall_floyd(10);

    ll ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a; cin >> a;
            if(a == -1) continue;
            ans += M[a][1];
            //cout << M[i][j] << " ";
        }
        //cout << endl;
    }


    cout << ans << endl;
    return 0;
}

