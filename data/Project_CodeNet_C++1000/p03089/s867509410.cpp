#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> ans;
    rep(i,n) cin >> b[i];
    bool ok=true;
    rep(i,n){
        if(b[i]>i+1) ok=false;
    }
    if(ok){
        int cnt=n-1;
        while(1){
            for(int i=cnt;0<=i;--i){
                if(b[i]==i+1){
                    ans.push_back(b[i]);
                    b.erase(b.begin()+i);
                    --cnt;
                    break;
                }
            }
            if(b.empty()) break;
        }
        reverse(ans.begin(),ans.end());
        rep(i,n){
            cout << ans[i] << "\n";
        }
        return 0;
    }else{
        cout << -1 << "\n";
        return 0;
    }
}   