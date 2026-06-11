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
    string s; cin >> s;
    for(int i=0; i<(int)s.size(); i++){
        if(i == K-1){
            s[i]=s[i]+('a'-'A');
            cout << s[i];
        }
        else cout << s[i];
    }
    cout << endl;
    return 0;
}