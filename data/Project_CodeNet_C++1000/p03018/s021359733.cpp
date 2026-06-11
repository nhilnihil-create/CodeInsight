#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    int t = S.size();
    ll ans = 0;
    vector<int> v;
    int p = 0;
    while(p<t){
        if(S[p]=='A'){
            v.push_back(0);
            p++;
            continue;
        }
        if(S[p]=='C'){
            v.push_back(-1);
            p++;
            continue;
        }
        if(S[p]=='B'){
            if(p==t-1||S[p+1]!='C') {
                v.push_back(-1);
                p++;
                continue;
            }
            else {
                v.push_back(1);
                p+=2;
                continue;
            }
        }
    }
    ll cnt = 0;
    reverse(v.begin(),v.end());
    rep(i,(int)v.size()){
        if(v[i]==1) cnt++;
        if(v[i]==0) ans+=cnt;
        if(v[i]==-1) cnt=0;
    }
    cout<<ans<<endl;
}