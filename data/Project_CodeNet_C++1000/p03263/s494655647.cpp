#include <bits/stdc++.h>

using namespace std;

struct Operation {
    int x;
    int y;
    int nx;
    int ny;
};

int main (void) {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H+1, vector<int>(W+1, 0));
    for ( int i = 1; i <= H; i++ ) {
        for ( int j = 1; j <= W; j++ )
            cin >> a.at(i).at(j);
    }

    int n_ope = 0;
    vector<Operation> ope;
    for ( int i = 1; i <= H; i++ ) {
        for ( int j = 1; j <= W; j++ ) {
            /* すでに偶数なら操作しない */
            if ( a.at(i).at(j) % 2 == 0 ) {
                continue;
            }

            /* 奇数の場合は偶数にする
             *   最終的に最終行右端列以外は偶数にできる */
            if ( j != W ) {
                /* 右端列以外なら右のマスに渡す */
                n_ope++;
                ope.push_back({j, i, j+1, i});
                a.at(i).at(j)--;
                a.at(i).at(j+1)++;
            }
            else if ( i != H ) {
                /* 最終行以外なら下のマスに渡す */
                n_ope++;
                ope.push_back({j, i, j, i+1});
                a.at(i).at(j)--;
                a.at(i+1).at(j)++;
            }
        }
    }

    cout << n_ope << endl;
    for ( int i = 0; i < n_ope; i++ ) {
        printf("%d %d %d %d\n",
               ope.at(i).y, ope.at(i).x,
               ope.at(i).ny, ope.at(i).nx);
    }
    return 0;
}
