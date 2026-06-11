#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
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
#define MAX 1000000007

int main()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q),r(q);
    rep(i,q)cin >> l[i] >> r[i];
    vector<int> count(n);
    rep(i,n-1){
        if(s[i]=='A'&&s[i+1]=='C'){
            count[i+1]=count[i]+1;
        }else{
            count[i+1]=count[i];
        }
    }
    rep(i,q){
        cout << count[r[i]-1]-count[l[i]-1] << endl;
    }


}