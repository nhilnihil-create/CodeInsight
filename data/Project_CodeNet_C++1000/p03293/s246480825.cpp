#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    string S, T; cin >> S >> T;
    ll len = S.length();
    string s = S;
    rep(i,len) {

        if (T == s) {
            cout << "Yes" << endl;
            exit(0);
        }
        char last = s[len-1];
        rep(j,len) {
            s[len-1-j] = s[len-2-j];
        }
        s[0] = last;
//        cout << s << endl;

    }
    cout << "No" << endl;

    

}
