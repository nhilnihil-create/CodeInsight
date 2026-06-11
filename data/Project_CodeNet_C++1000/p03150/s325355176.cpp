#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    ll n = s.size();
    string key = "keyence";
    ll i, j;
    for(i=0; i<7; i++)
        if(s[i] != key[i]) break;
    for(j=0; j<7; j++)
        if(s[n-1-j] != key[7-1-j]) break;
    cout << (i+j >= 7 ? "YES" : "NO") << endl;
}
