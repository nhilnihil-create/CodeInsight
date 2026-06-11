#include <iostream>
#include <map>
#include <ctime>
using namespace std;


void solve()
{
    int N; cin >> N;
    map<int,int> M;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        M[a]++;
    }
    
    long long ans = 0;
    for (auto m: M){
        if (m.first > m.second) ans += m.second;
        else ans += abs(m.first - m.second);
    }

    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}