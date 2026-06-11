#include <bits/stdc++.h>
using namespace std; 
const int maxn = 100500;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, ans = 0;
    cin >> n;
    for(long long i = 1 ; i * i <= n ; ++i)
        if(n % i == 0){
            int a = i - 1;
            long long b = (n / i) - 1;
            if(a && (n / a) == (n % a)) ans += a;
            if(b && (n / b) == (n % b)) ans += b;
        }
    cout << ans << '\n';
    return 0;

}