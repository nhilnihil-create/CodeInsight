#include <algorithm>
#include <climits>
#include <cmath>
#include<set>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
//#define dbg
#define p std::pair
#define vec std::vector
#define umap std::unordered_map
#define mp std::make_pair
#define all(cont) (cont).begin(), (cont).end()
#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);

int main()
{
    int n, k;
    cin >> n >> k;
    umap<int,int> m;
    int tmp;
    rep(i, n)
    {

        cin >> tmp;
	if(m.find(tmp)!=m.end()){
		++m.at(tmp);
	}else{
		m.insert(mp(tmp,1));
	}
    }vec<p<int,int>> v;
    for(const auto c:m){
v.push_back(move(c));
    }
    sort(all(v),[](p<int,int> l,p<int,int>r){return l.second>r.second;});
#ifdef dbg
    rep(i,v.size()){
	    cout<<'v'<<v[i].first<<' '<<v[i].second<<endl;
    }
#endif
    ll ans=0;
    if(v.size()<=k){
	    cout<<0<<endl;return 0;
    }
    while(v.size()!=k){
	    ans+=v[v.size()-1].second;
	    v.pop_back();
	    //v.shrink_to_fit();
    }
    cout<<ans<<endl;
    return 0;
}

ll extgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) {
        is_prime[i] = true;
    }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (unsigned ll j = 2 * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}
