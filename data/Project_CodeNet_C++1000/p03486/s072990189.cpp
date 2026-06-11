#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S,T;
    cin >> S >> T;
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    reverse(T.begin(),T.end());
    int count = 0;
    if (S < T) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
}
