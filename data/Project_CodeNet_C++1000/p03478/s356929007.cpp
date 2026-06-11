#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;

    for(int i = 1; i <= N; ++i){
        int a = i % 10 + i/10 % 10 + i/100 % 10 + i/1000 % 10 + i/10000;
        if (a >= A && a <= B) ans += i; 
    }
    cout << ans << endl;
}