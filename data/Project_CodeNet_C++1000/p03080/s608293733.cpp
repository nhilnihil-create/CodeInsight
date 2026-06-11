#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int r = 0,b = 0;
    char s;
    for(int i = 0;i < N;i++) {
        cin >> s;
        if(s == 'R') r++;
        else b++;
    }
    if(r > b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
