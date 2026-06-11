#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
 
using namespace std;
int MOD = 1000000007;
int gcd(int a,int b){
    if(a < b){
        int c = a;
        a = b;
        b = c;
    }
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}
signed main(){

    int t;
    cin >> t;
    rep(i,t){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a < b || d < b){
            cout << "No" << endl;
            continue;
        }else if(c+1 >= b){
            cout << "Yes" << endl;
            continue;
        }
        if(a%b > c){
            cout << "No" << endl;
            continue;
        }
        int x = gcd(d,b);
        if(b-c-1 >= x){
            cout << "No" << endl;
            continue;
        }
        if((a%b)%x + b - x > c && (a%b)%x + b - x < b){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://agc026.contest.atcoder.jp/tasks/agc026_b
