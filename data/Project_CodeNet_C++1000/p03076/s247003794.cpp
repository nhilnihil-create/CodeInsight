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
    vi time(5);
    for(int i=0; i<5; i++) cin >> time[i];
    vi ord(5);
    for(int i=0; i<5; i++) ord[i]=i;
    int ans=INF;
    do{
        int sum=0;
        for(int i=0; i<5; i++){
            if(i == 4) sum+=time[ord[i]];
            else sum+=(time[ord[i]]+9)/10*10;
        }
        chmin(ans, sum);
    }while(next_permutation(all(ord)));
    cout << ans << endl;
    return 0;
}