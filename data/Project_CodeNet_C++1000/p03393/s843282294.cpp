#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    string S;
    cin >> S;
    vector<bool> vec(26);
    for(int i = 0;i < S.size();i++) {
        vec.at(S.at(i) - 'a') = true;
    }
    if(S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    else if(S.size() < 26) {
        cout << S;
        for(int i = 0;i < 26;i++) {
            if(vec.at(i) == false) {
                char a = 'a' + i;
                cout << a << endl;
                break;
            }
        }
    }
    else {
        for(int i = S.size() - 1;i >= 0;i--) {
            for(int j = S.at(i) - 'a' + 1;j < 26;j++) {
                if(vec.at(j) == false) {
                    for(int k = 0;k < i;k++) {
                        cout << S.at(k);
                    }
                    char a = 'a' + j;
                    cout << a << endl;
                    return 0;
                }
            }
            vec.at(S.at(i) - 'a') = false;
        }
    }
}