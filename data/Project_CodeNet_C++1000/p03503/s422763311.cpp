#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool f[n][10];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> f[i][j];
        }
    }
    int p[n][11];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }

    int refven=-1*INT32_MAX;
//    cout << refven << "\n";
    for(int bit = 1; bit < (1<<10); ++bit) {
        int ven=0;
        for(int j = 0; j < n; j++) {
            int dopen=0;
            for(int i = 0; i < 10; i++) {
                if((bit&(1<<i))&&f[j][i]==true) dopen++;
            }
            ven+=p[j][dopen];
        }
        refven=max(refven,ven);
    }
    cout << refven << "\n";

    return 0;
}