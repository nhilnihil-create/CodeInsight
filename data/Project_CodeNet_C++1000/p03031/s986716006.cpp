#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, m;
    cin >> n >> m;
    vec s[m];
    rep(i, m){
        int k;
        cin >> k;
        rep(j, k){
            int s_;
            cin >> s_;
            s_--;
            s[i].push_back(s_);
        }
    }
    int p[m];
    rep(i, m) cin >> p[i];
    int ans = 0;
    for (int i = 0; i < (1 << n); i++){
        bool flag = true;
        rep(j, m){
            int num = 0;
            rep(k, s[j].size()){
                if(((i >> s[j][k]) & 1) == 1) num++;
            }
            // cout << num << endl;
            if(num % 2 != p[j]) flag = false;
        }
        if(flag) ans++;
        // cout << i << " " << flag << endl;
    }
    cout << ans << endl;    
}