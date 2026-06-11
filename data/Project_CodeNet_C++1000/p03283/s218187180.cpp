#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int table[510][510];
int sum[510][510];
int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    int l,r;
    int p,q;

    rep(i,M){
        cin >> l >> r;
        table[l][r]++;
    }
    rep(i,510){
        sum[i][0] = table[i][0]; 
        reps(j,1,510){
            sum[i][j] = sum[i][j-1] + table[i][j];
        }
    }

    ll tot;
    rep(i,Q){
        tot = 0;
        cin >> p >> q;
        reps(j,p,q+1){
            tot += (sum[j][q] - sum[j][p-1]);
        }
        cout << tot << endl;
    }

    return 0;
}