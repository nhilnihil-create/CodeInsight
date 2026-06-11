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

int main(){
    string S;
    int K;
    cin>>S>>K;
    set<string> s;
    int N = S.size();
    rep(i,5){
        rep(j,N-i){
            string t;
            for(int k = j; k < j+i+1; k++){
                t+=S[k];
            }
            s.insert(t);
        }
    }
    auto ite = s.begin();
    rep(i,K-1) ite++;
    cout<<*ite<<endl;
}