#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=(1LL<<60);
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    int N; cin >> N;
    vi A(N), B(N), C(N);
    for(auto &x : A) cin >> x;
    for(auto &x : B) cin >> x;
    for(auto &x : C) cin >> x;
    sort(all(A));
    sort(all(C));
    ll res=0;
    for(int i=0; i<N; i++){
        ll x, y;
        x=lower_bound(all(A), B[i])-A.begin();
        y=C.end()-upper_bound(all(C), B[i]);
        res+=x*y;
    }
    cout << res << endl;
    return 0;
}