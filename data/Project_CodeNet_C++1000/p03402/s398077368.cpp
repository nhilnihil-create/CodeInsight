#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b;
    cin >> a >> b;
    printf("%d %d\n", 100, 100);
    int b_cnt = 1;
    int w_cnt = 1;
    rep(i, 100) {
        rep(j, 100) {
            if ( j < 50 ) {
                if ( b_cnt < b && i % 2 == 1 && j % 2 == 0 ) {
                    ++b_cnt;
                    cout << "#";
                    continue;
                }
                cout << ".";
            } 
            else {
                if ( w_cnt < a && i % 2 == 1 && j % 2 == 1 ) {
                    ++w_cnt;
                    cout << ".";
                    continue;
                }
                cout << "#";
            }
        }
        cout << endl;
    }
    return 0;
}
