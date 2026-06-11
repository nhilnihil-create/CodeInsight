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

const int n_max = 100050;
vector<vector<int>> root(n_max);

vector<int> color(n_max, 0);
vector<bool> visited(n_max, false);

bool fds(int v, int c){
    color[v] = c;  
    visited[v] = true;
    for (auto next: root[v]){
        if (color[next] == c) return false;
        if (color[next] == -c) continue; 
        if (!fds(next, -c)) return false;
    }
    return true;
}


int main()
{
    ll n, m;
    cin >> n >> m;
    
    rep(i, m){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        root[tmp1].push_back(tmp2);
        root[tmp2].push_back(tmp1);
    }

    ll ans = 0;
    if (fds(0, 1)){
        //二部グラフ
        ll one = 0;
        rep(i, n){
            //cout << color[i] << endl;
            if (color[i]==1) one++; 
        }
        ans = one*(n-one);
    } else {
        ans = n*(n-1)/2;
    }

    cout << ans-m << endl;

}

