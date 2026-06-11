#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    char b;
    cin >> b;
    char ans;
    if(b == 'A') {
        ans = 'T';
    }
    if(b == 'T') {
        ans = 'A';
    }
    if(b == 'G') {
        ans = 'C';
    }
    if(b == 'C') {
        ans = 'G';
    }
    cout << ans << endl;
    return 0;
}
