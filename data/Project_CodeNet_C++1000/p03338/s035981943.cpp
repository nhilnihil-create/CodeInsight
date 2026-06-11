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
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 1; i<n-1; ++i){
        string x = s.substr(0,i);
        string y = s.substr(i,n-i);

        set<char> x_set,y_set;
        rep(j,i) x_set.insert(x[j]);
        rep(k,n-i) y_set.insert(y[k]);

        int cnt = 0;
        for(auto l : x_set){
            for(auto m : y_set){
                if(l==m) ++cnt;
            }
        }
        if(ans<cnt) ans = cnt;
    }
    cout(ans);


    return 0;
}