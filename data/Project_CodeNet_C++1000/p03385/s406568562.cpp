#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
void Yes() {
    cout << "Yes" << endl;
}
void No() {
    cout << "No" << endl;
}
int main(void) {
    string s; cin >> s;
    sort(s.begin(), s.end());
    bool ok = false;
    do {
        if(s == "abc") ok = true;
    } while (next_permutation(s.begin(), s.end()));
    if(ok) Yes();
    else No();
}
