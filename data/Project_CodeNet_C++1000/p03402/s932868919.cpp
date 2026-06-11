#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;


/*
A<=500 B<=500

Aが白,Bが黒
とりま100*100

最初全部白埋め

100 * 100 マスで、50*20だけモザイク埋めすると
最初どちらも500

白い領域内のポチポチと、黒い領域内のポチポチ

各50 * 100 領域に白と黒を取る

縦に24マス、横に49マスまで取れるので500は余裕

*/

char res[500][500];

int main() {
    int A, B; cin >> A >> B;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) res[i][j] = '#';
    }
    for (int i = 50; i < 100; i++) {
        for (int j = 0; j < 100; j++) res[i][j] = '.';
    }
    A--;B--;

    for (int a = 0; a < A; a++) {
        res[2 * (a / 50)][2 * (a % 50)] = '.';
    }
    for (int b = 0; b < B; b++) {
        res[51 + 2 * (b / 50)][2 * (b % 50)] = '#';
    }
    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << res[i][j];
        } cout << endl;
    }




}

