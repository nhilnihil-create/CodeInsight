#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    string a, t;
    cin >> a >> t;
    sort(a.begin(), a.end());
    sort(t.rbegin(), t.rend());
    cout << ((a < t)?"Yes":"No");
    return 0;
}

