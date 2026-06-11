#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, h, w, c;
    cin >> h >> w;
    char s[h+1][w+1]={};

    for (j=1; j<h+1; j++) {
        for (i=1; i<w+1; i++) {
            cin >> s[j][i];
        }
    }

    for (j=1; j<h+1; j++) {
        for (i=1; i<w+1; i++) {
            if (s[j][i] == '.') {
                c=0;
                if (s[j-1][i-1]=='#') c++;
                if (s[j-1][i]=='#') c++;
                if (s[j-1][i+1]=='#') c++;
                if (s[j+1][i-1]=='#') c++;
                if (s[j+1][i]=='#') c++;
                if (s[j+1][i+1]=='#') c++;
                if (s[j][i-1]=='#') c++;
                if (s[j][i+1]=='#') c++;
                cout << c;
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    cout << endl;
}
