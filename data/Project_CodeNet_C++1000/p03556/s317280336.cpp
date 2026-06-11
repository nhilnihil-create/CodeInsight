#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    
    int ans = 1;
    for (int i = 1; i * i <= N; i++) {
        ans = max(ans, i*i);
    }
    cout << ans << endl;
}