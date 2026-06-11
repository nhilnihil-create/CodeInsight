// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_Z = 100;
int N = 0;
int M = 0;

void input_NM(void);
void input_XYZ(void);
void init_unionfind(void);
int root(int);
void unite(int, int);

int par[MAX_N];
int check[MAX_N];

int main()
{
    input_NM();
    input_XYZ();
    for (int i = 0; i < N; i++) {
        check[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        check[root(i)] = 1;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += check[i];
    }

    cout << sum;
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

/// <summary>
/// NとMを入力させるだけの関数
/// </summary>
void input_NM(void) {
    cin >> N >> M;
}

/// <summary>
/// X,Y,Zを入力し、木構造を作る
/// </summary>
void input_XYZ(void) {
    int x, y, z;
    init_unionfind();
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        unite(x-1, y-1);
    }
}

/// <summary>
/// parの初期化、全ての要素の親は自分
/// </summary>
void init_unionfind(void) {
    for (int i = 0; i < MAX_N; i++) {
        par[i] = i;
    }
}

/// <summary>
/// データxが∉木の根を再帰で得る
/// </summary>
int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

/// xとyの木を併合
void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
}