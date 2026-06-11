#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a , ll b){
	if(b == 0) return a;
	return gcd(b , a % b);	
}
ll lcm(ll a , ll b){
	ll g = gcd(a , b);
	ll lc = (a/g) * b;
	return lc;
}

template <typename T>
T median(std::vector<T>& c)
{
    size_t n = c.size();
    std::nth_element(c.begin(), c.begin() + n, c.end());
    return c[(n+1)/2];
}

int MAX_N=200000;

int main(){
    ios::sync_with_stdio(false);
    ll n;
    vector<ll> x(MAX_N+5);
    ll y[MAX_N+5];
    cin >> n;
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n){
        y[i] = 2*x[i];
    }
    sort(y,y+n);
    ll m = (y[(n/2)-1]+y[n/2])/2; 
    rep(i,n){
        if(2*x[i] <= m) cout << y[n/2]/2 << endl;
        else cout << y[n/2-1]/2 << endl;
    }
    return 0;
}