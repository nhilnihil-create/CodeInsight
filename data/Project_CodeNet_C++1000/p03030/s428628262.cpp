#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector <string> S(N);
    vector <int> P(N) , T(N);
    vector <tuple<string , int , int>> A(N);
    for(int i = 0; i < N; i++){
        cin >> S[i] >> P[i];
        T[i] = i;
        A[i] = make_tuple(S[i] , -P[i] , T[i]);
    }
    sort(A.begin() , A.end());
    for(int i = 0; i < N; i++){
        cout << get<2>(A[i]) + 1 << endl;
    }
}
