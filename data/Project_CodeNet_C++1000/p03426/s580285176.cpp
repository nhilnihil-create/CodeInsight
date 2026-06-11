#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int H, W, D, Q;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    vector<pair<int, int>> pa(W * H);
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> A.at(i).at(j);
            pa.at(A.at(i).at(j) - 1) = make_pair(i, j);
        }
    }
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, 0, Q){
        cin >> L.at(i) >> R.at(i);
    }
    vector<int> S_cost(H * W);
    for (int k = 0; k < D; k++){
        int fin = H * W - k;
        int num = (fin + D - 1) / D;
        S_cost.at(fin - 1) = 0;
        for (int j = 1; j < num; j++){
            int x_1 = pa.at(fin - D * (j - 1) - 1).second;
            int y_1 = pa.at(fin - D * (j - 1) - 1).first;
            int x_0 = pa.at(fin - D * j - 1).second;
            int y_0 = pa.at(fin - D * j - 1).first;
            int cost = abs(x_1 - x_0) +abs(y_1 - y_0);
            S_cost.at(fin - D * j - 1) = S_cost.at(fin - D * (j - 1) - 1) + cost;
        }
    }
    rep(i, 0, Q){
        cout << S_cost.at(L.at(i) - 1) - S_cost.at(R.at(i) - 1) << endl;
    }
}
