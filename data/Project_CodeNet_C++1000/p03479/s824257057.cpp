#include <iostream>
#include <ctime>
using namespace std;


void solve()
{
    long long a,x,y;
    cin >> x >> y;
    a = x;
    int cnt = 0;
    long long dbl = 2;
    while (a <= y){
        ++cnt;
        a = dbl * x;
        dbl *= 2;
    }
    cout << cnt << endl;
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