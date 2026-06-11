#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    string s; cin >> s;
    int blue = 0, red = 0;
    rep(i, s.size()){
        if(s[i] == '0')red++;
        else blue++;
    }
    cout << min(red, blue) * 2 << endl;
}
