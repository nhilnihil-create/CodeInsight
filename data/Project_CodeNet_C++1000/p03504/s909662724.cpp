#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, C; cin >> n >> C;
    vector<vector<P>> ch(C);
    rep(i,n){
        int s, t, c; cin >> s >> t >> c;
        --c;
        ch[c].push_back(P(s,t)); 
    }
    rep(i,C) sort(ALL(ch[i]));
    for(int i = 0; i < C; i++){
        for(int j = 0; j < (int)ch[i].size() - 1; j++){//cast
            if(ch[i][j].second == ch[i][j+1].first){
                ch[i][j+1].first = ch[i][j].first;
                ch[i][j] = P(1,0);
            }
        }
    }    
    for(int i = 0; i < C; ++i){
        for(int j = 0; j < ch[i].size(); j++){
            ch[i][j].first--;
        }
    }
    vector<int> num(100005);
    for(int i = 0; i < C; i++){
        for(int j = 0; j < ch[i].size(); j++){
            num[ch[i][j].first]++;
            num[ch[i][j].second]--;
        }
    }
    for(int i = 0; i <= 100000; i++){
        num[i+1] += num[i];
    }
    int res = 0;
    for(int i = 0; i <= 100000; i++){
        res = max(res, num[i]);
    }
    cout << res << endl;
    return 0;
}