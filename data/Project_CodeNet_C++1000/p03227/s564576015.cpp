#include <algorithm>
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
int main() {
    string s;
    cin >> s;
    if(s.size() == 3) {
        rep(i, 3) cout << s[2 - i];
        cout << endl;
    } else {
        cout << s << endl;
    }
}