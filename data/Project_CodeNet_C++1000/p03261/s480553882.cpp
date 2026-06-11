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
    cin >> n;
    vector<string> w(n);
    map<string, int> z;
    rep(i,n){
        cin >> w[i];
        z[w[i]] += 1; 
    }
    for(auto x : z){
        if(x.second>=2){
            cout("No");
            return 0;
        }
    }

    bool can = true;
    rep(i,n-1){
        int l = (int)w[i].size();
        string end = w[i].substr(l-1,1);
        string start = w[i+1].substr(0,1);
        if(end != start){
            can = false;
            break;
        }
    }

    if(can) cout("Yes");
    else cout("No");
    return 0;

}