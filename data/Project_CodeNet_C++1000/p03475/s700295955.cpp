#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N; vector<int> C,S,F;
void input()
{
    cin >> N;
    C.resize(N); S.resize(N); F.resize(N);
    for (int i = 0; i < N-1; ++i){
        cin >> C[i] >> S[i] >> F[i];
    }   
}

void solve()
{
    vector<int> dep_time(N-1);
    for (int i = 0; i < N-1; ++i){
        dep_time[i] = S[i];
        for (int j = i+1; j < N-1; ++j){
            if (dep_time[j-1] + C[j-1] <= S[j]) dep_time[j] = S[j];
            else {
                if ((dep_time[j-1] + C[j-1]) % F[j] == 0) dep_time[j] = dep_time[j-1] + C[j-1];
                else dep_time[j] = ((dep_time[j-1] + C[j-1]) / F[j] + 1) * F[j];
            }
        }
        cout << dep_time[N-2] + C[N-2] << endl;
    }
    cout << 0 << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}