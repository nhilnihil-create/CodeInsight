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
    string s;
    cin >> s;

    int l = (int)s.size();
    int min_dist = 1e9;
    for(int i=0; i<=l-3; ++i){
        string t = s.substr(i,3);
        int a = ((int)t[0]-'0')*100 + ((int)t[1]-'0')*10 + ((int)t[2]-'0');
        int dist = abs(753 - a);
        if(min_dist>dist) min_dist = dist;
    }
    cout(min_dist);
    return 0;
}