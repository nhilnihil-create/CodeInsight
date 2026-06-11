#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
    #include "/home/v-o_o-v/deb.h"
    #define deb(x...)cerr << "[" << #x << "] = [";_print(x);
#else
    #define deb(x...)
#endif

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int x = stoi(s.substr(0, 2)), y = stoi(s.substr(2));
    if((x > 12 && y > 12) || (x == 0 && y == 0))puts("NA");
    else if((x > 12 && y == 0) || (x == 0 && y > 12))puts("NA");
    else if(x <= 12 && y <= 12 && x > 0 && y > 0)puts("AMBIGUOUS");
    else if(x <= 12 && x > 0)puts("MMYY");
    else puts("YYMM");
    return 0;
}
// Write Here
