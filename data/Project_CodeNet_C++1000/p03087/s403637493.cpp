#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}


int main(){
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    vi cnt(N+1, 0);
    for(int i=1; i<N; i++){
        if(s[i-1] == 'A' && s[i] == 'C'){
            cnt[i+1]=cnt[i]+1;
        }
        else cnt[i+1]=cnt[i];
    }
    while(Q--){
        int l, r; cin >> l >> r;
        cout << cnt[r]-cnt[l] << endl;
    }
    return 0;
}