#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> x(n+1),y(n+1);
    vector<pair<int,int>> p;
    rep(i,n) {
        int t;cin >> t;
        cin >> x[i] >> y[i];
        p.push_back({t,i});
    }
    x[n]=0,y[n]=0;
    p.push_back({0,n});
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++){
        int dis=abs(x[p[i].second]-x[p[i+1].second])+abs(y[p[i].second]-y[p[i+1].second]);
        if(dis>p[i+1].first-p[i].first){
            cout << "No" << endl;
            return 0;
        }
        if(dis%2!=(p[i+1].first-p[i].first)%2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}