#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> fac(MX);
vector<int> ifac(MX);

long long fpow(long long a,long long n){
  long long ret=1;
  if(n==1) return a;
  if(n%2==0) {
      ret = fpow(a*a%mod, n/2) %mod ;
  }else {
      ret = (a%mod)*fpow(a*a%mod, n/2) %mod;
  }
  return ret %mod;
}

int comb(int a, int b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}

int P(int a, int b) {
    int res = comb(a,b);
    res *= fac[b];
    return res % mod;
}

int ans, k;
vector<int> to[100005];
void dfs(int v, int p=-1) {
    for(int u: to[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    int nk = (p==-1) ? k : k-2;
    int c = (p==-1) ? to[v].size()+1 : to[v].size()-1;
    ans *= P(nk, c);
    ans %= mod;
}

char a[1002][1002];
signed main(){
    int h, w;
    cin >> h >> w;

    queue<pair<int, pair<int, int>>> q;
    FOR(i, 1, h+1) {
        string str;
        cin >> str;
        FOR(j, 1, w+1) {
            a[i][j] = str[j-1];
            //cout << a[i][j] << endl;
            if(a[i][j]=='#') q.push(make_pair(0, make_pair(i,j)));
        }
    }

    int cnt = 0;
    while(q.size()>0) {
        int i = q.front().second.first;
        int j = q.front().second.second;
        int depth = q.front().first;
        //cout << depth <<" " << i <<" " << j << endl;
        cnt = depth;
        q.pop();

        if(a[i-1][j]=='.') {
            a[i-1][j] = '#';
            q.push(make_pair(depth+1, make_pair(i-1,j)));
        }if(a[i][j-1]=='.') {
            a[i][j-1] = '#';
            q.push(make_pair(depth+1, make_pair(i,j-1)));
        }if(a[i+1][j]=='.') {
            a[i+1][j] = '#';
            q.push(make_pair(depth+1, make_pair(i+1,j)));
        }if(a[i][j+1]=='.'){
            a[i][j+1] = '#';
            q.push(make_pair(depth+1, make_pair(i,j+1)));
        }

    }
    cout << cnt << endl;


    return 0;
}
