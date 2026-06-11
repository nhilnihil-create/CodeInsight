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

    vector<pii> re;
    int cnt=0;
    for(int i=0; i<N+1; i++){
        if(S[i] == '1') cnt++;
        else{
            int pos=i;
            while(pos < N+1 && S[pos] != '1') pos++;
            if(pos == N+1) re.push_back({cnt, pos-i-1});
            else re.push_back({cnt, pos-i});
            cnt=0;
            i=pos-1;
        }
    }
    if((int)re.size() <= K){
        cout << S.size() << endl;
        return 0;
    }

    if(cnt >= 0) re.push_back({cnt, 0});
    
    int sum=0;
    for(int i=0; i<K; i++){
        sum+=re[i].first+re[i].second;
    }
    sum+=re[K].first;
    int ans=sum;
    for(int i=K; i<(int)re.size(); i++){
        sum+=re[i].second-re[i-K].first-re[i-K].second;
        if(i != (int)re.size()-1) sum+=re[i+1].first;
        chmax(ans, sum);
    }
    cout << ans << endl;
    return 0;
}