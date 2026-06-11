#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;

int main() {
    abdelrahman010
    string s;
    cin >> s;
    char cur1 = '1' , cur2 = '0';
    int cnt1 = 0 , cnt2 = 0;
    for(auto &i : s) {
        cnt1 += (cur1 != i);
        cnt2 += (cur2 != i);
        if(cur1 == '0')
            cur1 = '1' , cur2 = '0';
        else
            cur1 = '0' , cur2 = '1';
    }
    cout << min(cnt1 , cnt2);
    return 0;
}