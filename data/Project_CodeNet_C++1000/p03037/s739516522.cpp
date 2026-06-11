#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<ll>>;
#define MAX 1000000007

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    vector<int> pass_num(n,0);
    rep(i,m){
        cin >> l[i] >> r[i];
        l[i]--;r[i]--;
    }
    rep(i,m){
        pass_num[l[i]]++;
        pass_num[r[i]+1]--;
    }
    rep(i,n-1)pass_num[i+1]+=pass_num[i];
    int ans=0;
    rep(i,n){
        if(pass_num[i]==m){
            ans++;
        }
    }
    cout << ans << endl;
}