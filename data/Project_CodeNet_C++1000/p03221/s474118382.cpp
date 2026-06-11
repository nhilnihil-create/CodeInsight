#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
string solve(int n){
    string s;
    s = "000000";
    for(int i = 0; i < 6; i++){
        s[5-i] = '0'+n%10;
        n /= 10;
    }
    return s;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<map<int,int>> mp(n+1);
    for(int i = 0; i < m; i++){
        int p,y;
        cin >> p >> y;
        mp[p][y] = i;
    }
    vector<string> ans(m);
    for(int i = 1; i <= n; i++){
        int j = 1;
        for(auto r:mp[i]){
            string ken = solve(i);
            string num = solve(j);
            ans[r.second] = ken+num; 
            j++;
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
}