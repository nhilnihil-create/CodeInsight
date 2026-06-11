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
const ll MOD=1e9+7;


int main(){
    int N; cin >> N;
    vi C(N), V(N);
    for(auto &x : V) cin >> x;
    for(auto &x : C) cin >> x;
    int ans=0;
    for(int i=0; i<N; i++){
        if(V[i] >= C[i]) ans+=V[i]-C[i];
    }
    cout << ans << endl;
    return 0;
}