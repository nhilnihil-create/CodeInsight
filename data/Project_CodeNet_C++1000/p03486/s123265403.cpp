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
#define MAX 1000000007

int main()
{
    string s,t;
    cin >> s;
    cin >> t;
    ssort(s);
    rsort(t);
    rep(i,min(s.size(),t.size())){
        if(s[i]<t[i]){
            Yes;return 0;
        }else if(s[i]>t[i]){
            No;return 0;
        }
    }
    if(s.size()==t.size()){
        No;
    }else if(s.size()<t.size()){
        Yes;
    }else{
        No;
    }


}