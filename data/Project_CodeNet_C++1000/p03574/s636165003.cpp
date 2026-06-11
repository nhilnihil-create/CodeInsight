#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, c;
    cin >> h >> c;
    int arr[h][c];
    vector<string> s(h, "");
    loop(i, h) cin >> s[i];
    loop(i, h) {
        loop(j, c) {
            if(s[i][j] == '.') {
                int count = 0;
                if(i-1 >= 0 && j-1 >= 0 && s[i-1][j-1] == '#') count++;
                if(i-1 >= 0 && j >= 0 && s[i-1][j] == '#') count++;
                if(i-1 >= 0 && j+1 < c && s[i-1][j+1] == '#') count++;
                if(i >= 0 && j-1 >= 0 && s[i][j-1] == '#') count++;
                if (i >= 0 && j+1 < c && s[i][j+1] == '#') count++;
                if(i+1 < h && j-1 >= 0 && s[i+1][j-1] == '#') count++;
                if(i+1 < h && j >= 0 && s[i+1][j] == '#') count++;
                if(i+1 < h && j+1 < c && s[i+1][j+1] == '#') count++;
                arr[i][j] = count;
            }
        }
    }
    loop(i, h) {
        loop(j, c) {
            if(s[i][j] == '.') cout << arr[i][j];
            else cout << '#';
        } cout << endl;
    }
    return 0;
}
