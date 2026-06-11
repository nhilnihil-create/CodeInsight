#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    ll x, y;
    cin>> x >> y;
    ll num=x, ans=0;
    while(num <= y){
        ans++;
        num*=2;
    }
    cout << ans << endl;
    return 0;
}