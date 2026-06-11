#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<ll> dup;
ll size,start,last;
vector<int> a(5);
int k;
int res = 0;

void dfs(ll i){
    if(i == size){
        if( abs(a[dup[0]]-a[dup[1]]) > k ) res = 1;
    }else{
        if(i == 0){
            for(int j=start;j<=last;j++){
                dup[i] = j;
                dfs(i+1);
            }
        }else{
            for(int j=dup[i-1];j<=last;j++){
                dup[i] = j;
                dfs(i+1);
            }
        }
    }
}



int main(){
    FIN;
    rep(i,0,5) cin >> a[i];
    cin >> k;

    size = 2; start = 0; last = 4;
    dup.resize(size);
    dfs(0);

    if(res == 0) cout <<"Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}

