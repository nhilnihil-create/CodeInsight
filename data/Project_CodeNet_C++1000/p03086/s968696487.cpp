/*
    Problem 3
    https://atcoder.jp/contests/abc122/tasks/abc122_b
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<char> atcg {'A', 'T', 'C', 'G'};
/* function */
void solve1() {
    // 尺取法による解答
    string S;
    cin >> S;
    int lenATCG = 0;
    int r = 0;
    for (int l = 0; l < S.size(); l++) {
        while (r < S.size() && count(atcg.begin(), atcg.end(), S[r]))
            r++;
        lenATCG = max(lenATCG, r - l);
        l = r;
        r++;
    }
    cout << lenATCG << '\n';
}

void solve2() {
    // 部分列の右と左端のペアを全探索する解法
    string S;
    cin >> S;
    int lenATCG = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = i; j < S.size(); j++) {
            bool isATCG = true;
            for (int k = i; k <= j; k++)
                if (count(atcg.begin(), atcg.end(), S[k]) == 0) isATCG = false;
            if (isATCG) lenATCG = max(lenATCG, j - i + 1);
        }
    }
    cout << lenATCG << '\n';
}
/* main */
int main(){
    solve1();
    // solve2();
}