#include <bits/stdc++.h>
using namespace std;
using vi   = vector<int>;
using vll  = vector<long long>;
using vvi  = vector<vi>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;

int main() {
    string S; cin >> S;
    int ans = 0, tmp = 0;
    set<char> key;
    key.insert('A');
    key.insert('C');
    key.insert('G');
    key.insert('T');
    for(int i = 0; i < S.length(); i++) {
        if(key.count(S.at(i))){
            tmp++;
        } else {
            if (ans < tmp) ans = tmp;
            tmp = 0;
        }
    }
    if (ans < tmp) ans = tmp;
    cout << ans << endl;
}