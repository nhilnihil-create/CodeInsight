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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    vi pos;
    for(int i=0; i<N; i++){
        pos.push_back(i);
        int cur=i;
        while(cur < N && S[cur] == S[i]) cur++;
        i=cur-1;
    }

    int ans=0;
    for(int i=0; i<(int)pos.size(); i++){
        if(S[pos[i]] == '0'){
            if(i+2*K >= (int)pos.size()) chmax(ans, N-pos[i]);
            else chmax(ans, pos[i+2*K]-pos[i]);
        }
        else{
            if(i+2*K+1 >= (int)pos.size()) chmax(ans, N-pos[i]);
            else chmax(ans, pos[i+2*K+1]-pos[i]);
        }
    }
    cout << ans << endl;
    return 0;
}