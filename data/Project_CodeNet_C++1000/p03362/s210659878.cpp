#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=(1LL<<61)-1;

vector<int> pn;
vector<bool> is_prime(60000,true);
void make_prime(){
    for(int x=2;x*x<=60000;x++){
        int i=2;
        while(x*i<=60000){
            is_prime[x*i] = false;
            i++;
        }
    }
    is_prime[1] = false;
    for(int i=1;i<=60000;i++){
        if(is_prime[i]) pn.push_back(i);
    }
}


int main(){
    int N; cin >> N;
    make_prime();
    vector<ll> ans;
    int cnt = 0;
    for(auto it: pn){
        if(it%5==1){
            ans.push_back(it);
            cnt++;
        }
        if(cnt>=N) break;
    }
    rep(i,N) cout << ans[i] << " " ;
    cout << endl;
}