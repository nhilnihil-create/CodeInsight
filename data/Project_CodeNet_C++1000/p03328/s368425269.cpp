#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    vector<int>towers(999);
    towers[0] = 1;
    for (int i=1; i<999; i++){
        towers[i] = i+1 + towers[i-1];
    }
    int a, b;
    cin >> a >> b;
    int diff = b-a;
    for (int i=0; i<998; i++){
        if(diff == towers[i+1] - towers[i]){
            cout << towers[i] - a << endl;
            return 0;
        }
    }
}