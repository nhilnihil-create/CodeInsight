#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, cnt = 1, flag = 0;
    cin >> x;
    set<int> s;
    while(s.find(x) == s.end()) {
        s.insert(x);
        if(x%2) { //odd
            x = 3*x + 1;
        } else { //even
            x /= 2;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
