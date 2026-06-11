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
    string s;
    cin >> s;
    vector<int> count_char(26,0);
    vector<int> count_char2(26,0);
    int num=0;
    int ans=0;
    rep(i,n){
        count_char[s[i]-'a']++;
    }

    for(int i=0;i<n-1;++i){
        count_char[s[i]-'a']--;
        count_char2[s[i]-'a']++;

        if(count_char[s[i]-'a']>0&&count_char2[s[i]-'a']==1){
            num++;
        }else if(count_char[s[i]-'a']==0&&(count_char[s[i]-'a']+count_char2[s[i]-'a'])>1){
            num--;
        }
        ans=max(ans,num);
    }
    cout << ans << endl;
}