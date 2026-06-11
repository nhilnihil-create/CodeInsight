#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;

int main(){
    ll n;
    cin>>n;
    vector<ll> even(100001, 0), odd(100001,0);
    REP(i,n){
        ll a;
        cin>>a;
        if(i%2==0){
            even[a]++;
        }else{
            odd[a]++;
        }
    }
    ll even_max=MAX(even);
    ll odd_max=MAX(odd);
    auto even_dis=distance(even.begin(), max_element(even.begin(),even.end()));
    auto odd_dis=distance(odd.begin(), max_element(odd.begin(),odd.end()));

    sort(ALL(even),greater<ll>());
    sort(ALL(odd),greater<ll>());
    ll ans;
    if(even_dis!=odd_dis){
        ans=n-even_max-odd_max;
    }else{
        ans=n-max(even[0]+odd[1], even[1]+odd[0]);
    }
    cout<<ans;
    return 0;
}
