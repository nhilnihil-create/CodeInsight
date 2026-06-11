#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    
    int ans = A+B+C;
    int sum = max({A,B,C});
    ans -= sum;

    for (int i = 0; i < K; i++) {
        sum *= 2;
    }
    cout << ans + sum << endl;
}