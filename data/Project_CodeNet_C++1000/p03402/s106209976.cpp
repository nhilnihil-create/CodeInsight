#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;
    A--;
    B--;

    vector<vector<char> > ans(100, vector<char>(100));

    int a = 0;
    int b = 0;

    for(int i = 1; i < 50; i += 2) {
        for(int j = 1; j < 100; j += 2) {
            if(a == A) break;
            ans[i][j] = '.';
            a++;
        }
    }

    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 100; j++) {
            if(ans[i][j] != '.') ans[i][j] = '#';
        }
    }

    for(int i = 51; i < 100; i += 2) {
        for(int j = 1; j < 100; j += 2) {
            if(b == B) break;
            ans[i][j] = '#';
            b++;
        }
    }

    for(int i = 50; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(ans[i][j] != '#') ans[i][j] = '.';
        }
    }

    cout << 100 << " " << 100 << endl;

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}