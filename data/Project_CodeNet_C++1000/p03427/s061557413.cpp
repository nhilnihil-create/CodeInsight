#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
    string s;
    cin >>s;
    int n = s.size();
    bool ok = true;
    rep(i,n){
        if(s[i]!='9') ok = false;
    }
    if(ok) {
        cout << 9*n <<endl;
        return 0;
    }
    else {
        bool ok2 = true;
        rep(i,n-1){
            if(s[i+1]!='9') ok2 = false;
        }
        if(ok2){
            int c = s[0]-'0';
            cout << 9*(n-1)+c <<endl;
            return 0;
        }
        if(s[0]=='1'){
            cout << 9*(n-1) <<endl;
        }
        else {
            int c = s[0]-'0';
            cout << 9*(n-1)+c-1 <<endl;
        }
    }
}