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
/* main */
int main(){
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