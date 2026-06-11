#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    string s; cin >> s;
    int ans = 0;
    rep(i, 4) if(s[i] == '2') ans++;
    print(ans);
}

