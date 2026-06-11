#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

string S; ll K;
void input()
{
    cin >> S >> K;
}

void solve()
{
    char ans;
    for (int i = 0; i < S.length(); ++i){
        if (S[i] != '1'){
            ans = S[i];
            break;
        } else {
            if (K == 1) {
                ans = S[i];
                break;
            } else {
                --K;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}