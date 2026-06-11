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
    int N; cin >> N;
    map<string, int> mpr;
    for(int i=0; i<N; i++){
        string s; cin >> s;
        mpr[s]++;
    }
    int M; cin >> M;
    map<string, int> mpb;
    for(int i=0; i<M; i++){
        string t; cin >> t;
        mpb[t]++;
    }

    int ans=0;
    for(auto p : mpr){
        int sum=p.second;
        if(mpb.count(p.first)) sum-=mpb[p.first];
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}