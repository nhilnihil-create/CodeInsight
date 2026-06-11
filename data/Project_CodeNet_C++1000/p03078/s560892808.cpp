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
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> a(x), b(y), c(z);
    for(auto &v : a) cin >> v;
    for(auto &v : b) cin >> v;
    for(auto &v : c) cin >> v;
    
    vector<ll> s1;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            s1.push_back(a[i]+b[j]);
        }
    }
    sort(all(s1), greater<ll>{});
    vector<ll> s2;
    for(int i=0; i<min(k, (int)s1.size()); i++) s2.push_back(s1[i]);

    vector<ll> s3;
    for(int i=0; i<(int)s2.size(); i++){
        for(int j=0; j<z; j++){
            s3.push_back(s2[i]+c[j]);
        }
    }
    sort(all(s3), greater<ll>{});
    for(int i=0; i<k; i++) cout << s3[i] << endl;
    return 0;
}