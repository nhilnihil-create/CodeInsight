#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> csf(n);
    rep(i, n-1){
        int c, s, f; cin >> c >> s >> f;
        csf[i] = tie(c, s, f);
    }

    rep(st, n){
        int time = 0;
        for (int i = st; i < n-1; i++)
        {
            int c, s, f;
            tie(c, s, f) = csf[i];
            if (time <= s){
                time = s;
            } else {
                time += (time%f != 0) ? (f-time%f) : 0; 
            }
            time += c;            
        }
        cout << time << endl;    
    }
}

