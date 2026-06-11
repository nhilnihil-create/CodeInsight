#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> A(2, vector<ll>(N));
    for (int i = 0; i < 2; i++){
      for (int j = 0; j<N; j++)cin >> A[i][j];
    }

    vector<ll> top(N);
    top[0] = A[0][0];
    for (int i = 1; i < N; i++)top[i] = top[i-1] + A[0][i];

    vector<ll> under(N);
    under[N-1] = A[1][N-1];
    for (int i = N-2; i>=0; i--)under[i] = under[i + 1] + A[1][i];
    
    ll out = 0;
    for (int i = 0; i<N; i++){
      out = max(out, top[i] + under[i]);
    }
    cout << out << endl;
    return 0;
}