#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    int sr, sc;
    cin >> sr >> sc;

    string s, t;
    cin >> s >> t;

    int flag = 0;  // flag = 0 のとき駒は盤上にある

    // 左に動かして外に出す場合
    int now = sc;  // いま駒のある列
    rep(i, n) {

        if(s[i] == 'L') {
            now--;
        }

        if(now < 1) {
            flag = 1;
            break;
        }

        if(now < w && t[i] == 'R') {
            now++;
        }

    }

    // 右に動かして外に出す場合
    now = sc;
    rep(i, n) {

        if(s[i] == 'R') {
            now++;
        }

        if(w < now) {
            flag = 1;
            break;
        }

        if(1 < now && t[i] == 'L') {
            now--;
        }
        
    }

    // 上に動かして外に出す場合
    now = sr;  // いま駒のある行
    rep(i, n) {

        if(s[i] == 'U') {
            now--;
        }

        if(now < 1) {
            flag = 1;
            break;
        }

        if(now < h && t[i] == 'D') {
            now++;
        }
        
    }

    // 下に動かして外に出す場合
    now = sr;
    rep(i, n) {
        
        if(s[i] == 'D') {
            now++;
        }

        if(h < now) {
            flag = 1;
            break;
        }

        if(1 < now && t[i] == 'U') {
            now--;
        }
        
    }

    if(flag) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    cout << endl;
    return 0;
}