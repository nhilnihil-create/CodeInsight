#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    ll k = 1;
    ll l = 2;
    ll m = 1;
    vector<ll> ans;
    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(3);
    ans.push_back(9);
    ll cnt = N - 4;
    if(cnt < 1){
        PR(ans,N);
        return 0;
    }
    while(cnt > 1){
        if(k*6+4 > 30000) break;
        ans.push_back(k*6+2);
        ans.push_back(k*6+4);
        cnt -= 2;
        k++;
    }
    while(cnt > 1){
        if(l*6+3+6 > 30000) break;
        ans.push_back(l*6+3);
        l++;
        ans.push_back(l*6+3);        
        cnt -= 2;
        l++;
    }
    while(cnt > 0){
        if(m*6 > 30000) break;
        ans.push_back(m*6);
        m++;
        cnt--;
    }
    PR(ans,N);
}