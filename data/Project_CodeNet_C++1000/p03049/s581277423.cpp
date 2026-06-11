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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    int count=0;
    int a_b_exist=0;
    int a,b;a=b=0;
    rep(i,n){
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A'){
            a_b_exist++;
        }
        if(s[i][0]=='B'){
            b++;
        }
        if(s[i][s[i].size()-1]=='A'){
            a++;
        }
    }
    count=min(a,b);
    if(a==b&&b==a_b_exist&&count>0){
        count--;
    }
    rep(i,n){
        rep(j,s[i].size()-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B'){
                count++;
            }
        }
    }
    cout << count << endl;
}