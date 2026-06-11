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

using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 10000000

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> fact;
    vector<ll> fact_;
    int count=0;
    for(int i=1;i*i<=m;++i){
        if(m%i==0){
            fact.push_back(i);
        }
    }
    count=fact.size();
    fact_=fact;
    ll max=0;
    for(int i=0;i<count;++i){
        fact_.push_back(m/fact[i]);
        
    }
    rep(i,fact_.size()){
        if(fact_[i]>max&&m/fact_[i]>=n){
            max=fact_[i];
        }
    }
    cout << max << endl;
}