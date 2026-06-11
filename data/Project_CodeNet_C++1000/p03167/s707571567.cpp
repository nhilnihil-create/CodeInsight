#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;
    
/*
    Author: Koushik Sahu
    Created: 11 Sep 2020 20:40:55
*/

ll h, w, dp[1001][1001];
char a[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>h>>w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }
    fill_n(dp[0], 1001*1001, 0);
    dp[0][0] = 1;
    bool flag = false;
    for(int i=0; i<h; i++){
        if(!flag){
            if(a[i][0]=='.'){
                dp[i][0] = 1;
            }else{
                break;
            }
        }
    }
    for(int j=0; j<w; j++){
        if(!flag){
            if(a[0][j]=='.'){
                dp[0][j] = 1;
            }else{
                break;
            }
        }
    }
    for(int i=1; i<h; i++){
        for(int j=1; j<w; j++){
            if(a[i][j]=='.') dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
    return 0;
}