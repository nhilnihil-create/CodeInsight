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
using Graf=vector<vector<int>>;
using Graf_bool=vector<vector<bool>>;
#define MAX 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> t(n+1),x(n+1),y(n+1);
    rep(i,n)cin >> t[i+1] >> x[i+1] >> y[i+1];
    rep(i,n){
        int dist=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        int timeDist=t[i+1]-t[i];
        if(timeDist<dist){
            No;
            return 0;
        }else{
            if(timeDist%2!=dist%2){
                No;return 0;
            }
        }
    }
    Yes;
}