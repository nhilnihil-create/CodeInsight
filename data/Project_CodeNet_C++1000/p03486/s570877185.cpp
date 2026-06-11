#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S, T;
    cin >> S >> T;
    vector<char> vS, vT;
    for (char c : S) vS.push_back(c);
    for (char c : T) vT.push_back(c);
    sort(vS.begin(), vS.end());
    sort(vT.begin(), vT.end(), greater<char>());
    string sortedS, sortedT;
    for (char c : vS) sortedS += c;
    for (char c : vT) sortedT += c;
    cout << (sortedS < sortedT ? "Yes" : "No") << '\n';
}
