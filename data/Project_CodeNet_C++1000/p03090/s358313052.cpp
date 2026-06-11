#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

int main()
{
    int n;
    cin >> n;
    int k = n+1-n%2;
    vvi g(n+1);
    int m = 0;
    repran(i, 1, n){
        repran(j, i+1, n+1){
            if (i+j ==k ) continue;
            g[i].push_back(j);
            m++;
        }
    }
    cout << m << endl;
    rep(i, n) rep(j, g[i+1].size()) cout << i+1 << " " << g[i+1][j] << endl;
}