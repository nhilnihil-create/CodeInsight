#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, M, A, B, C;
    string s, s2;
    cin >> s;
    int ans = 0;
    int tmp = 0;
    rep(i, s.size()){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') tmp++;
        else tmp = 0;
        ans = max(ans, tmp);        
    }
    cout << ans << endl;
}