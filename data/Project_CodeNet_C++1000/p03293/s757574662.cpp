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

string rotate(string moji){
    string result = "";
    result += moji[moji.size()-1];
    rep(i, moji.size()-1){
        result += moji[i];
    }
    return result;
}

int main(){
    string s; cin >> s;
    string t; cin >> t;

    bool flg = false;
    string tmp = s;
    rep(i,s.size()){
        if(tmp == t){
            flg = true;
            break;
        }
        tmp = rotate(tmp);
    }

    if(flg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
