#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s < t) {
                cout << "Yes" << endl;
                return 0;
        }
        string tr = "";
        for (int i = t.size()-1; i >=0; i--) {
                tr += t[i];
        }
        if (s < tr) {
                cout << "Yes" << endl;
        }
        else cout << "No" << endl;

        return 0;
}