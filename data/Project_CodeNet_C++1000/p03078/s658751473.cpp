#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll>a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    priority_queue<pair<ll,vector<int>>> pq;
    pq.push(make_pair(a[0]+b[0]+c[0],vector<int>({0,0,0})));
    vector<ll>ans;
    set<vector<int>>s;
    while(ans.size()<k) {
        auto v = pq.top();pq.pop();
        ans.push_back(v.first);
        rep(i,3) {
            int A = v.second[0];
            int B = v.second[1];
            int C = v.second[2];
            if(i==0)A++;
            if(i==1)B++;
            if(i==2)C++;
            
            if(A==x || B == y || C==z) continue;
            if(!s.count(vector<int>({A,B,C}))) {
                s.insert(vector<int>({A,B,C}));
                pq.push(make_pair(a[A]+b[B]+c[C],vector<int>({A,B,C})));
            }
        }
    }
    rep(i,k) cout << ans[i] << endl;
}