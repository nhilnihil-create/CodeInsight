#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int n;

bool is_valid() {
    if (s[n-1]=='1') {
        return false;
    }
    if (s[0]=='0')
        return false;
    for (int i=0; i<n/2; ++i) {
        if (s[i]!=s[n-2-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> s;
    n=s.size();
    if (!is_valid()) {
        cout << -1;
        return 0;
    }
    int cur_root=1;
    int cur_size=n-1;
    int cur_v=2;
    for (int i=(n-1)/2; i>=0; --i) {
        if (s[i]=='1') {
            int sub_size=i+1;
            for (int k=0; k<cur_size-sub_size; ++k) {
                cout << cur_v << ' ' << cur_root << endl;
                ++cur_v;
            }
            cout << cur_v << ' ' << cur_root << endl;
            cur_size=i;
            cur_root=cur_v;
            ++cur_v;
        }
    }
    return 0;
}