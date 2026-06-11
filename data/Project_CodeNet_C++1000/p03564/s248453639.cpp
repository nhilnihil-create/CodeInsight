#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int N,K;
    cin >> N >> K;
    
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        int sum = 1; 
        for (int j = 1; j <= i; j++) {
            sum *= 2;
        }
        sum += K*(N-i);
        ans = min(ans, sum);
    }
    cout << ans << endl;
}