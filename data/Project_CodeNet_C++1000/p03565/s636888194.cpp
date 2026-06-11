#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    vector<string> ans; //答えになりうる文字列の配列
    int l = s.size() - t.size() + 1;

    for (int i = 0; i < max(0, l); i++) { //文字列の比較位置
        string tmp = s;
        for (int j = 0; j < t.length(); j++) { //部分文字列の比較位置
            if (i + j > s.size() - 1) break; //そもそも部分文字列の方が長かったらunrestorable
            if (tmp[i + j] == '?' || tmp[i + j] == t[j]) //文字列のi+j番目が?もしくは、tのj番目と同じだったら
                tmp[i + j] = t[j]; //文字列のi+j番目をtのj番目にする
            else
                break;
            if (j == t.length() - 1) { //?が埋まらなかった場合の処理
                for (int k = 0; k < tmp.length(); k++) {
                    if (tmp[k] == '?') tmp[k] = 'a'; //辞書順なので?だったらaを入れる
                }
                ans.push_back(tmp); //配列に追加
            }
        }
    }

    // 選べる区間は |𝑆| − |𝑇| + 1 個あるので, それらの区間すべてに対して 「選んだ区間が決定している 状態での辞書順最小」 を求め, その中での辞書順最小なものが, 全部の中の辞書順最小となります。
    sort(ans.begin(), ans.end()); //辞書順で一番小さな答えになりえる文字列をans[0]にする
    cout << (ans.size() > 0 ? ans[0] : "UNRESTORABLE") << endl;
    return 0;
}