#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h+2,vector<char>(w+2,'.'));
    for (int i = 1; i < h+1; i++) {
        for (int j = 1; j < w+1; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < h+1; i++) {

        for (int j = 1; j < w+1; j++) {
            int cnt =0;
            if(a[i][j]=='#'){
                continue;
            }
            if (a[i][j] == '.'){
                if (a[i][j-1]=='#'){
                    cnt++;
                }
                if (a[i][j+1]=='#'){
                    cnt++;
                }
                if (a[i-1][j-1]=='#'){
                    cnt++;
                }
                if (a[i+1][j+1]=='#'){
                    cnt++;
                }
                if (a[i+1][j-1]=='#'){
                    cnt++;
                }
                if (a[i-1][j+1]=='#'){
                    cnt++;
                }
                if (a[i+1][j]=='#'){
                    cnt++;
                }
                if (a[i-1][j]=='#'){
                    cnt++;
                }
                a[i][j] = '0'+cnt;

            }
        }
    }
    for (int i = 1; i < h+1; i++) {
        for (int j = 1; j < w+1; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    


    return 0;
}