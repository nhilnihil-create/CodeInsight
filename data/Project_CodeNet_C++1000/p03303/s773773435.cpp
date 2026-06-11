#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    int w;
    cin >> w;
    int tmp_num = 0;
    while(1) {
        if ( tmp_num > s.length() - 1 ) {
            break;
        } 
        cout << s[tmp_num];
        tmp_num += w;
    }
    cout << endl;
    return 0;
}
