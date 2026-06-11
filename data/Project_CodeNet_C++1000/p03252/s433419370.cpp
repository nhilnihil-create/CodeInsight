#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S, T;
    cin >> S >> T;
    vector<int> s(26,-1),e(26,-1);
    for (int i=0;i<S.size();i++){
        int a = S[i] - 'a';
        int b = T[i] - 'a';
        if (s[a] != -1 || e[b] != -1){
            if (s[a] != b || e[b] != a){
                cout << "No" << "\n";
                return 0;
            }
        }
        s[a] = b;
        e[b] = a;
    }
    cout << "Yes" << "\n";
    return 0;
}