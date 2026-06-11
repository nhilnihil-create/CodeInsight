#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<int>A(X),B(Y),C(Z);
    for(int i = 0; i < X; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < Y; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < Z; i++) {
        cin >> C[i];
    }
    vector<int>AB;
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            AB.push_back(A[i]+B[j]);
        }
    }
    sort(AB.rbegin(),AB.rend());
    vector<int>ABC;
    for(int i = 0; i < min(K,(int)AB.size()); i++) {
        for(int j = 0; j < Z; j++) {
            ABC.push_back(AB[i]+C[j]);
        }
    }
    sort(ABC.rbegin(),ABC.rend());
    for(int i = 0; i < K; i++) {
        cout << ABC[i] << endl;
    }
}
