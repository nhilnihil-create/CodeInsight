#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll k; 
    cin >> k;
    int one = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') 
            one++;
        else break;
    }
    if (k <= one) cout << 1 << '\n';
    else cout << s[one] << '\n';
    return 0;
}