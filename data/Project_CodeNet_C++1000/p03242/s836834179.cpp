#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    string n; cin >> n;
    rep(i,3) {
    if (n[i] == '1') cout << "9";
    else if (n[i] == '9') cout << "1";
    }
    cout << endl;


}
