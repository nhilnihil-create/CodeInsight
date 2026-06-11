#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    map<int, int> ball;
    
    int n,k,a; cin>>n>>k;
    
    rep(i,n){
        cin>>a;
        ball[a]++;
    }
    
    if(ball.size()<=k){
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> count;
    
    for(auto p: ball){
        count.push_back(p.second);
    }
    sort(count.begin(), count.end());
    
    int ans = 0;
    
    rep(i,count.size()-k){
        ans += count[i];
    }
    
    cout << ans << endl;
    return 0;
}