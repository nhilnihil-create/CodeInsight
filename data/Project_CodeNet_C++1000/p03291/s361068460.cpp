#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    ll a = 0, b = 0, c = 0;
    ll p = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') a = (a + p) % MOD;
        if(s[i] == 'B') b = (b + a) % MOD;
        if(s[i] == 'C') c = (c + b) % MOD;
        if(s[i] == '?'){
            c = (c * 3 + b) % MOD;
            b = (b * 3 + a) % MOD;
            a = (a * 3 + p) % MOD;
            p = p * 3 % MOD;
        }
    }
    cout << c << endl;
}
