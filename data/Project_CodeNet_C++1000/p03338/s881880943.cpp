#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int maxcnt=0;
    for (int i=1; i<s.size(); i++) {
        //文字列分割
        string s1, s2;
        s1=s.substr(0,i);
        s2=s.substr(i,s.size());

        //sortしておく
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        //文字をカウント
        char cbuff=' ';
        int cnt=0;
        rep(i,s1.size()) {
            if (cbuff==s1.at(i)) continue;
            if (s2.find(s1.at(i))!=string::npos) cnt++;
            cbuff=s1.at(i);
        }

        //最大カウント数
        maxcnt=max(maxcnt, cnt);
    }

    cout << maxcnt << endl;
    return 0;
}