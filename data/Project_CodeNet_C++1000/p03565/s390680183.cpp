#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s, t;
    cin >> s >> t;
    int N = (int)s.size();
    int n = (int)t.size();

    //ヒントの文字列Tを入れることができる部分の、最初のインデックスを格納する配列
    vector<int> able;

    //tが、答えとなる文字列Sの中に入る余地があるかどうかチェックする
    bool is = false;
    rep(i, N-n+1){
        //ヒント文字列Tとの比較用に部分文字列を抜き出す
        string part = s.substr(i, n);
        //ヒント文字列Tと、部分文字列で条件1を満たすかを判定するための変数
        bool match = true;
        rep(j, n){
            if(part[j] == '?') continue;
            else if(part[j] != t[j]) match = false;
        }
        if(match) able.push_back(i);
    }
    //条件1を満たすような部分が存在しないならば、答えを出力
    if(able.empty()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    //条件1を満たすような部分が存在する時
    int len = (int)able.size();
    vector<string> variety(len);
    rep(j, len){
        string S = "";
        int key_index = able[j];
        rep(i, N){
            if(i == key_index){
                S += t;
                i += (n-1);
            }else if(s[i] == '?'){
                S.push_back('a');
            }else if(s[i] != '?'){
                S.push_back(s[i]);
            }
        }
        variety[j] = S;
    }
    sort(variety.begin(), variety.end());
    string ans = variety[0];
    cout << ans << endl;
    return 0;
}