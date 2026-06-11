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
    vi x(5);
    for(int i=0; i<5; i++) cin >> x[i];
    int k; cin >> k;
    sort(all(x));
    bool ans=false;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(x[j]-x[i] > k) ans=true;
        }
    }
    cout << (ans?":(":"Yay!") << endl;
    return 0;
}