#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }

    else {
        return gcd(y, x % y);
    }
}

int main(){
    int N;
    cin>>N;
    vector<bool> ok(30005);
    rep(i,30005){
        if(i%2==0||i%3==0) ok[i] = true;
    }
    vector<int> ans;
    int t = 1;
    vector<bool> used(30005);
    while(ans.size()<N-1){
        if(ok[t]) {
            ans.push_back(t);
            used[t] = true;
        }
        t++;
    }
    int S = 0;
    for(auto x:ans) S+=x;
    rep(i,30001){
        if(i==0||i==1) continue;
        if(gcd(S,i)==1) continue;
        if((S+i)%6!=0) continue;
        if(used[i]) continue;
        ans.push_back(i);
        break;
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}