// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<char, char>m;
    string s, t;

    cin >> s ;
    cin >> t;
    vector<int>start(26, -1);
    vector<int>goal(26, -1);
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        
        int a = s[i] - 'a';
        int b = t[i] - 'a';

        if (start[a] != -1 || goal[b] != -1) {
            if (start[a] != b || goal[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            start[a] = b;
            goal[b] = a;
        }

        
    }

    
        cout << "Yes" << endl;

    
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
