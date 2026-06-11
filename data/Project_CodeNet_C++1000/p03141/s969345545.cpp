#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>
#include <queue>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBUG = true;

struct Dish{
    ll a;
    ll b;
    ll sum;
};

bool cmp(const Dish &a, const Dish &b){
    return a.sum < b.sum;
}

int main(){

    ll n;
    cin >> n;

    vector<Dish> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i].a >> d[i].b;
        d[i].sum = d[i].a + d[i].b;
    }

    sort(all(d), cmp);

    ll taka = 0;
    ll aoki = 0;
    while(true){
        taka += d.back().a;
        d.pop_back();
        if(d.size() == 0) break;
        
        aoki += d.back().b;
        d.pop_back();
        if(d.size() == 0) break;
    }

    cout << taka - aoki << endl;

}