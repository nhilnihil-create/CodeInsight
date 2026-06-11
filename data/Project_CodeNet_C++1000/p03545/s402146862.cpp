#include <iostream>
#include <ctime>
using namespace std;

int A; int B[3];
void input()
{
    cin >> A;
    B[0] = (A % 1000) / 100;
    B[1] = (A % 100) / 10;
    B[2] = A % 10;
    A /= 1000;
}

void solve()
{
    for (int i = 0; i < (1<<3); ++i){
        int sum = A;
        char op[3];
        for (int j = 0; j < 3; ++j){
            if (i & (1<<j)){
                op[j] = '+';
                sum += B[j];
            }
            else {
                op[j] = '-';
                sum -= B[j];
            }
        }
        if (sum == 7){
            cout << A << op[0] << B[0] << op[1] << B[1] << op[2] << B[2] << "=7" << endl;
            break;
        }
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}