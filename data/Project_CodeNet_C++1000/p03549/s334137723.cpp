#include <iostream>
#include <ctime>
using namespace std;

int N,M;
void solve()
{
    cin >> N >> M;
    int X = 1900 * M + 100 * (N-M);
    while (M > 0){
        X *= 2;
        --M;
    }
    cout << X << endl;
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