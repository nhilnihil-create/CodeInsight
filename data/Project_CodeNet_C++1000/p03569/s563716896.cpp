#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    string t1 = "",t2;
    rep(i, s.size()){
        if(s[i] != 'x') t1 += s[i];
    }
    t2 = t1;
    reverse(t1.begin(), t1.end());
    if(t1 != t2){
        cout << "-1" << endl;
        return 0;
    }
    vector<int> check;
    rep(i,s.size() + 1){
        int now = 0;
        int id = i;
        while(id < s.size() && s[id] == 'x'){
            id++;
            now++;
        }
        check.push_back(now);
        i = id;
    }
    int ans =  0;
    for(int i = 0; i * 2 < int(check.size()); i++){
        ans += max(check[i], check[check.size() - 1 - i]) - min(check[i], check[check.size() - 1 - i]);
    }
    cout << ans << endl;
    return 0;
}