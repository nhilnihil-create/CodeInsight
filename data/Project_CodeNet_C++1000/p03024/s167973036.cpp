#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S;
    cin >> S;
    if ((int)count(S.begin(), S.end(), 'x') >= 8) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
