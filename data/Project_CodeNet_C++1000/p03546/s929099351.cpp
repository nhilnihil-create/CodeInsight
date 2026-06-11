#include <bits/stdc++.h>
using namespace std;

int c[10][10];

void floyd() {
    for (int k=0; k<=9; ++k) {
        for (int i=0; i<=9; ++i) {
            for (int j=0; j<=9; ++j) {
                c[i][j]=min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    for (int i=0; i<=9; ++i) {
        for (int j=0; j<=9; ++j) {
            cin >> c[i][j];
        }
    }

    floyd();

    int sum=0;
    for (int i=1; i<=h; ++i) {
        for (int j=1; j<=w; ++j) {
            int x;
            cin >> x;
            if (x!=-1) {
                sum+=c[x][1];
            }
        }
    }

    cout << sum;

    return 0;
}
