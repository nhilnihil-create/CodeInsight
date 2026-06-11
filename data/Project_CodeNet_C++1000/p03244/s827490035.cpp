#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll ev[200000], od[200000];
    vector<pair<ll, ll> > even, odd;
    ll n;
    ll v;
    cin>>n;
    MEMSET(ev, 0); MEMSET(od, 0);
    rep(i, n){
        cin>>v;
        if(i%2==0) ev[v]++;
        else od[v]++;
    }
    rep(i, 200000) if(ev[i]!=0) even.push_back({ev[i], i});
    rep(i, 200000) if(od[i]!=0) odd.push_back({od[i], i});
    sort(all(even)); sort(all(odd));
    if(even[even.size()-1].second!=odd[odd.size()-1].second){
        cout<<n-even[even.size()-1].first-odd[odd.size()-1].first<<endl;
    }
    else{
        ll Maxim=0;
        if(even.size()>=2) Maxim=max(even[even.size()-2].first+odd[odd.size()-1].first, Maxim);
        if(odd.size()>=2) Maxim=max(even[even.size()-1].first+odd[odd.size()-2].first, Maxim);
        else if(even.size()==odd.size()) Maxim=n/2;
        cout<<n-Maxim<<endl;
    }
    return 0;
}
