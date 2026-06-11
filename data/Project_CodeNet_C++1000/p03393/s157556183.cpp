#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
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

int main()
{
    string s;
    cin >> s;
    vector<int> alph(26);
    rep(i,s.size()){
        alph[s[i]-97]++;
    }
    if(s.size()<=25){
        int c=26;
        int i=0;
        while(alph[i]!=0){
            i++;
        }
        c=i;
        cout << s+char(c+97) << endl;
    }else{
        if(s=="zyxwvutsrqponmlkjihgfedcba")cout << -1;
        else{
            string t=s;
            next_permutation(t.begin(),t.end());
            rep(i,s.size()){
                cout << t[i];
                if(s[i]!=t[i])return 0;
            }
        }
    }
    
}