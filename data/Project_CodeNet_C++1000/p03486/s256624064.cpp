#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<char>())
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
    string s,t;
    cin >> s;
    cin >> t;
    vector<int> s_(s.size()),t_(t.size());
    rep(i,s.size()){
        s_[i]=s[i];
    }
    rep(i,t.size()){
        t_[i]=t[i];
    }
    ssort(s_);
    rsort(t_);
    int i=0;
    int count=0;
    while(i<s_.size()&&i<t_.size()){
        if(s_[i]<t_[i]){
            Yes;
            return 0;
        }else if(s_[i]>t_[i]){
            break;
        }
        ++i;
    }
    if(i<s_.size()&&i<t_.size()){
        No;
    }else{
        if(s_.size()>=t_.size()){
            No;
        }else{
            Yes;
        }
    }
}