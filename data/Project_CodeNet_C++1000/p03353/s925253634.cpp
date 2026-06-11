#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){

    string s; cin >> s;
    int k; cin >> k;
    set<string> aa;
    rep(i, s.length()){
        for(int j = 0; j < k; ++j){
            aa.insert(s.substr(i, j + 1));
        }
    }
    auto it = aa.begin();
    rep(i, k - 1) it++;
    cout << *it << endl;

  
}