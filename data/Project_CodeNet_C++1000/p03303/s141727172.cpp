#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string s;
    ll n;
    cin >> s;
    cin >> n;
    for(ll i = 0; i < s.size(); i += n)cout << s[i];
    cout << endl;

    return 0;
}