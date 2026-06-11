#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
    int N,Q;
    cin>>N>>Q;
    string s;
    cin>>s;
    vector<vector<char>> q(Q,vector<char>(2));
    for(int i = 0; i < Q; i++) cin>>q[i][0]>>q[i][1];
    auto query=[&](int x){
        for(int i = 0; i < Q; i++){
            if(s[x]==q[i][0]){
                if(q[i][1]=='L') x--;
                else x++;
            }
            if(x<0) return -1;
            if(x>=N) return 1;
        }
        return 0;
    };
    int l = -1,r=N;
    while(r-l>1){
        int mid = (l+r)/2;
        if(query(mid)==-1)l = mid;
        else r=mid;
    }
    int L = r;
    l = -1;
    r = N;
    while(r-l>1){
        int mid = (l+r)/2;
        if(query(mid)==1)r = mid;
        else l=mid;
    }
    int R = l;
    cout<<R-L+1<<endl;
}