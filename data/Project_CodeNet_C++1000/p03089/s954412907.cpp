#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N;
    cin >> N;
    vector<int> b(N);
    rep(i, N) cin >> b[i];
    vector<int> ans;
    while(b.size() > 0){
        int t = -1;
        rep(i, b.size()){
            if(i == b[i]-1){
                t = i;
            }
        }
        if(t < 0) break;
        else{
            ans.push_back(t+1);
            b.erase(b.begin() + t);
        }
    }
    if(b.size() > 0){
        cout << -1 << endl;
    }else{
        rep(i, N){
            cout << ans[N-1-i] << endl;
        }
    }
    return 0;
}
