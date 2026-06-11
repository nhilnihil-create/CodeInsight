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
    int N;
    cin>>N;
    set<P> s;
    rep(i,N){
        for(int j = i+1; j<N; j++){
            s.insert(make_pair(i,j));
        }
    }
    if(N%2==0){
        rep(i,N/2){
            s.erase(make_pair(i,N-i-1));
        }
    }
    if(N%2==1){
        rep(i,N/2){
            s.erase(make_pair(i,N-i-2));
        }
    }
    cout<<s.size()<<endl;
    auto ite = s.begin();
    rep(i,s.size()){
        cout<<(*ite).first+1<<" "<<(*ite).second+1<<endl;
        ite++;
    }
}