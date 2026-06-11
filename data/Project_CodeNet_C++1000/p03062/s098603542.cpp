#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}



int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    ll ans=0, mn=LINF;
    int cnt=0;
    bool flag=false;
    for(int i=0; i<N; i++){
        if(A[i] < 0) cnt++;
        if(A[i] == 0) flag=true;
        mn=min(mn, llabs(A[i]));
        ans+=llabs(A[i]);
    }
    if(cnt%2 != 0 && !flag){
        ans-=2*mn;
    }
    cout << ans << endl;
    return 0;
}