#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,1e8);
    dp.at(0) = 0;
    vector<int> add(1,1);
    REP(i,1,20){
        int tmp = pow(6,i);
        if(tmp > n) break;
        add.push_back(tmp);
    }
    REP(i,1,20){
        int tmp = pow(9,i);
        if(tmp > n) break;
        add.push_back(tmp);
    }
    REP(i,1,n+1){
        for(int x : add){
            if(i-x<0) continue;
            dp.at(i) = min(dp.at(i), dp.at(i-x)+1);
        }
    }
    cout << dp.at(n) << endl;
}