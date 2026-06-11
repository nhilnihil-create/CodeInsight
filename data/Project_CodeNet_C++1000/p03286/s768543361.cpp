#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;

ll N;
void input()
{
    cin >> N;
}

void solve()
{
    if (N == 0){
        cout << 0 << endl;
        return;
    } else {
        int mod = -2;
        stack<int> stk;
        while (N != 0){
            // cout << N / mod << " " << N % mod << endl;
            if (N % mod == -1){
                stk.push(N % mod + 2);
                N = (N - N % mod - 2) / mod;
            } else {
                stk.push(N % mod);
                N = (N - N % mod) / mod;
            }
            
        }
        while (!stk.empty()){
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
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