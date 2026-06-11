#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>>p,q;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        p.push_back(make_pair(b,a));//(y,x)
    }
    rep(i,n) {
        int c,d;
        cin >> c >> d;
        q.push_back(make_pair(c,d));
    }
    sort(q.begin(),q.end());//青い点についてx座標が小さいものからみていく
    sort(p.rbegin(),p.rend());//赤い点についてy座標が大きいものからとる
    int ans = 0;
    vector<bool>flagp(n,true);
    vector<bool>flagq(n,true);
    rep(i,n) {
        if(!flagq[i]) continue;
        rep(j,n) {
            if(!flagp[j])continue; 
            if(p[j].second < q[i].first && p[j].first < q[i].second) {
                ans++;
                flagp[j] = false;
                flagq[i] = false;
                break;
            }
        }
    }
    
    cout << ans << endl;
}