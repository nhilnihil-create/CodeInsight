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
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    Graf g(h,vector<int>(w));
    rep(i,h){
        cin >> s[i];
    }
    rep(i,h){
        rep(j,w){
            int count_bom=0;
            if(i>0){
                if(j>0){
                    if(s[i-1][j-1]=='#'){
                        count_bom++;
                    }
                }
                if(s[i-1][j]=='#'){
                    count_bom++;
                }
                if(j<w-1){
                    if(s[i-1][j+1]=='#'){
                        count_bom++;
                    }
                }
            }
            if(j>0){
                if(s[i][j-1]=='#'){
                    count_bom++;
                }
            }
            if(j<w-1){
                if(s[i][j+1]=='#'){
                    count_bom++;
                }
            }
            if(i<h-1){
                if(j>0){
                    if(s[i+1][j-1]=='#'){
                        count_bom++;
                    }
                }
                if(s[i+1][j]=='#'){
                    count_bom++;
                }
                if(j<w-1){
                    if(s[i+1][j+1]=='#'){
                        count_bom++;
                    }
                }
            }
            g[i][j]=count_bom;
        }
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]!='#'){
                cout << g[i][j];
            }else{
                cout << '#';
            }
        }cout << endl;
    }
}