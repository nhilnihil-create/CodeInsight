#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    int x;
    cin >> x;

    if(x==1){
        cout(1);
        return 0;
    }
    int min_dif = 1e9;
    int ans = 0;
    for(int b=2; b<sqrt(1e3); ++b){
        for(int p=2; p<=9; ++p){
            int y = pow(b,p);
            int dif = x - y;
            if(dif>=0 && min_dif>dif){
                min_dif = dif;
                ans = y;
            }
        }
    }
    cout(ans);
    return 0;
}