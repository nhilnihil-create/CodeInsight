#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    cout << (s < t ? "Yes\n" : "No\n");
    return 0;
}