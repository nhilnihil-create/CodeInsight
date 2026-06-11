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
    string s; cin >> s;

    int ans=INF, cnt=0;
    int num=0;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i]-'0' != num) cnt++;
        num^=1;
    }
    chmin(ans, cnt);
    cnt=0, num=1;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i]-'0' != num) cnt++;
        num^=1;
    }
    chmin(ans, cnt);
    cout << ans << endl;
    return 0;
}