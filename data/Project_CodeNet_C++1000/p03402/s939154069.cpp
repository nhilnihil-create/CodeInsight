#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

char g[100][100];

int main() {
    int A, B; cin >> A >> B;
    rep(i, 100){
        rep(j, 100){
            if(i < 50){
                g[i][j] = '.';
            } else {
                g[i][j] = '#';
            }
        }
    }

    int cnta = 0;
    int cntb = 0;

    bool ch = false;
    for (int i = 0; i < 50; i+=2){
        for (int j = 0; j < 100; j+=2){
            if(cntb == B-1){
                ch = true;
                break;
            }
            g[i][j] = '#';
            cntb++;
        }
        if(ch)break;
    }

    ch = false;
    for (int i = 51; i < 100; i+=2){
        for (int j = 0; j < 100; j+=2){
            if(cnta == A-1){
                ch = true;
                break;
            }
            g[i][j] = '.';
            cnta++;
        }
        if(ch)break;
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100){
        rep(j, 100){
            cout << g[i][j];
        }
        cout << endl;
    }

    return 0;
}