#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, Y;
void input()
{
    cin >> N >> Y;
}

void solve()
{
    int ten = Y / 10000, five = (Y % 10000) / 5000, one =  (Y % 5000) / 1000;
    // cout << "first: " << ten << " " << five << " " << one << endl;
    for (int i = 0; i <= ten; ++i){
        for (int j = 0; j <= five + 2*i; ++j){
            // cout << ten-i << " " << five+2*i-j << " " << one+5*j << endl;
            if (ten + five + one + i + 4*j == N){
                cout << ten - i << " " << five + 2*i - j << " " << one + 5*j << endl;
                return;
            }
        }
    }

    cout << "-1 -1 -1 " << endl;
    return;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}