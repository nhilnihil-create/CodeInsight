#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long X, Y;
    cin >> X >> Y;
    
    long long sum = X;
    long long ans = 1;
    for (long long i = X+X; i <= Y; i+=X) {
        if (sum < i && i % sum == 0) {
            X += sum;
            sum = i;
            ans++;
        }
    }
    cout << ans << endl;
}