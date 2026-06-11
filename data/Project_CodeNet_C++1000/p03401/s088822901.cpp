#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N; vector<int> A;
void input()
{
    cin >> N;
    A.resize(N+2);
    A[0] = A[N+1] = 0;
    for (int i = 0; i < N; ++i) cin >> A[i+1];
}

void solve()
{
    int cost = 0;
    for (int i = 0; i < N+1; ++i){
        cost += abs(A[i+1] - A[i]);
    }
    for (int i = 1; i <= N; ++i){
        cout << cost - abs(A[i]-A[i-1]) - abs(A[i]-A[i+1]) + abs(A[i+1]-A[i-1]) << endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}