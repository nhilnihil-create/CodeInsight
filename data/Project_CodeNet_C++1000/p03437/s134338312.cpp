#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++) // for簡略表記
#define DUMP(ar) for(int loop=0; loop<(int)ar.size(); loop++) cout << "[" << loop << "]:" << ar[loop] << endl // 配列一覧表示
#define DUMPL(ar) for(int loop=0; loop<(int)ar.size(); loop++) { cout << ar[loop]; if(loop<(int)ar.size()-1) cout << ' '; } cout << endl; // 配列一行一覧表示
#define COUT(x) cout << x << endl // 単要素出力
#define ALL(ar) ar.begin(), ar.end() // コンテナの全要素
#define LOOPD(i) cout << "ループ[" << i << "]回目---------------" << endl // ループ回数デバグ
using namespace std;
// cout << fixed << setprecision(4) で小数点以下4桁の桁そろえ
// cout << setw(5) << ... で表示形式を5桁に設定 5桁未満なら頭に空白がつく 5桁越なら先頭から5桁まで
// cout << setw(5) << setfill('0') << ... で空白部分の埋め文字に5を使う
// getline(cin, [変数]); で空白などを含む入力の受け取り(行ごとの受け取り)
// cin >> ws; でそこまでにストリームに残されたホワイトスペースを取り除く(=以降のgetlineの有効化)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    if(x >= y){
        if(x % y == 0){
            COUT("-1");
            return 0;
     
        }
    }

    COUT(x);

    return 0;
}