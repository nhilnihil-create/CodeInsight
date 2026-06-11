#include <bits/stdc++.h>
using namespace std;


string s;
int x, y;
vector<int> v[2];
int dp[8005][16005];
int l ;
int rec(int pos, int sum){
    if(pos==v[l].size()){
        return sum==x;
    }
    int& ans = dp[pos][sum+8000];
    if(ans!=-1) return ans;
    return ans = max(rec(pos+1,sum+v[l][pos]), rec(pos+1,sum - v[l][pos]));
}




int main() {
    cin >> s >> x >> y;
    int id = 0, f = 1, cnt = 0;

    while(s[id]!='T' && id<s.size()) id++;
    for(int i=id+1;i<s.size();i++){
        if(s[i]=='T'){
            v[f].push_back(cnt);
            cnt = 0 , f ^= 1;
        } else cnt++;
    }
    v[f].push_back(cnt);
    memset(dp, -1, sizeof dp);
    int ok1 = rec(0,id);
    l = 1, x = y;
    memset(dp, -1, sizeof dp);
    int ok2 = rec(0,0);
    if(ok1 && ok2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}
