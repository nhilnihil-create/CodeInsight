#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

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
    ld ans=0;
    for(int i=1; i<=N; i++){
        int p=1, cnt=0;
        while(i*p < K){
            p*=2;
            cnt++;
        }
        ans+=(ld)1/N*pow(0.5, cnt);
    }
    cout << fixed << setprecision(10); 
    cout << ans << endl;
    return 0;
}