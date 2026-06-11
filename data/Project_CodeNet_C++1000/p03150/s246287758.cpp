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
    cin >> s;
    int n = s.size();
    if(s=="keyence") cout <<"YES" <<endl;
    else{
        rep(i,n){
            for(int j = 1;j<=n;++j){
                string t = s.substr(i,j);
                string x = s.substr(0,i);
                if(i+j>=n)continue;
                if(n-i-j<0)continue;
                string y = s.substr(i+j,n-i-j);
                if(x+y=="keyence"){
                    cout <<"YES" <<endl;
                    return 0;
                }
            }
        }
        cout << "NO" <<endl;
    }

}