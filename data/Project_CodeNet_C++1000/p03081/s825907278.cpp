#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 地点cにいるゴーレムが左(もしくは右)に抜けるか否かをシュミレート
int sim(int c, string &s, vector<char> &t, vector<char> &d) {
    for(int i = 0; i < t.size(); i++) {
        if(s[c] == t[i]) {
            c += (d[i] == 'L' ? -1 : 1);
        }
        if (c < 0) return 1;
        if (c >= s.size()) return 3;
    }
    return 2;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> t(Q), d(Q);
    for(int i = 0; i < Q; i++) {
        cin >> t[i] >> d[i];
    }    

    // ゴーレムはとなりのゴーレムを飛び越えることがないので、相対的位置関係が変わらない
    // ある地点で左に抜けるゴーレムがいたとき、そのひだりのゴーレムは全て抜ける
    // そのため、二分法でその座標を求めることができる

    // 左に抜けるケース
    int ok = -1, ng = N;
    while(abs(ng - ok) > 1) {
        int c = (ng + ok) / 2;

        if(sim(c, s, t, d) == 1) ok = c;
        else ng = c;
    }
    int ok_l = ok;

    // 右に抜けるケース
    ok = N, ng = -1;
    while(abs(ng - ok) > 1) {
        int c = (ng + ok) / 2;

        if(sim(c, s, t, d) == 3) ok = c;
        else ng = c;
    }
    int ok_r = ok;

    cout << (ok_r - ok_l - 1) << endl;

    return 0;
}