#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using ll = long long int;

int main()
{
    string S, T;
    cin >> S >> T;

    map<char, char> mp;
    for (ll i = 0; i < 26; i++)
    {
        mp['a' + i] = '_';
    }
    
    bool ok = true;
    for (ll i = 0; i < S.size(); i++)
    {
        if (mp[S[i]] != '_' && mp[S[i]] != T[i]) {
            ok = false;
        }
        mp[S[i]] = T[i];
    }

    mp.clear();
    for (ll i = 0; i < 26; i++)
    {
        mp['a' + i] = '_';
    }
    
    for (ll i = 0; i < T.size(); i++)
    {
        if (mp[T[i]] != '_' && mp[T[i]] != S[i]) {
            ok = false;
        }
        mp[T[i]] = S[i];
    }
    cout << (ok ? "Yes" : "No") << endl;
}