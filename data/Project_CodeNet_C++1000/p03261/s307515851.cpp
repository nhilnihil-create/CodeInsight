#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    int n; cin >> n;

    set<string> word;
    vector<string> w_list(n);

    rep(i, n){
        cin >> w_list[i];
        word.insert(w_list[i]);
    }
    if(word.size() != n){
        cout << "No" << endl;
        return 0;
    }

    string hoge = w_list[0];
    char s = hoge[hoge.size()-1];

    bool flg = true;
    repr(i, 1, n){
        string tmp = w_list[i];
        if(s != tmp[0]) flg = false;
        s = w_list[i][w_list[i].size()-1];
    }

    if(flg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
