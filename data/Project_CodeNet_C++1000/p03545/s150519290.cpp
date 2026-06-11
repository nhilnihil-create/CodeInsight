#include<bits/stdc++.h>
using namespace std;
/*
alias p='g++ -std=c++17 -O2 pra.cpp'
alias pg='g++ -std=c++17 -O2 -g pra.cpp'
alias s='g++ -std=c++17 -O2 -g subpra.cpp'
alias ss='g++ -std=c++17 -O2 -g sspra.cpp'
ulimit -c unlimited
alias a='./a.out'
cd programming
cd cpp
cd practice

*/
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); i++)
//if (i) cout << " "; で最初のみ空白文字を出力することができる
#define Sort(v) sort((v).begin(), (v).end())
#define pb push_back
using veci = vector<int>;
using vecs = vector<string>;
using vecd = vector<double>;
using vecl = vector<long long>;
using G = vector<vector<int>>;
using P = pair<int, int>;
double PI = acos(-1);
ll lINF = LLONG_MAX; ll lmINF = LLONG_MIN;
int INF = INT_MAX; int mINF = INT_MIN;
//const ll mod = 1000000007;
int main() {
    cout.precision(10);
    cin.tie(0);//cin高速化
    string a;
    cin >> a;
    vecs s(3, " ");
    for (int bit=0; bit < (1<<3); bit++){//2通りある部分で、全パターンの列挙
        int ans=a[0]-'0';
        for(int i=0; i<3; i++){
            if (bit&(1 << i)){//フラグが立っていれば
                s[i] = "+";
                ans += a[i+1]-'0';
            }
            else{
                s[i] = "-";
                ans -= a[i+1]-'0';
            }
        }
        if (ans == 7){
            cout << a[0] << s[0] << a[1] << s[1] << a[2] << s[2] << a[3] << "=7" << endl;
            return 0;
        }
    }
    return 0;
}