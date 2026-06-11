#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > //第二成分の大きさが関係ない
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


    ll N ;
    cin >> N;

    ld k = (-1.0 + sqrt(1.0 + 8.0*N))/2.0;
    ll siz = k;
    if((siz * (siz+1)) != (2*N)){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << siz+1<< endl;

    vector< vector<ll> > ans;

    ll till = 0;
    rep(i, siz+1){
        vector<ll> ret;
        ll now = ans.size();
        if(now >0){
            rep(i, now){
                ret.pb(ans[i][now-1]);
            }
        }

        now = siz - ret.size();
        rep(i, now){
            till++;
            ret.pb(till);
        }
        ans.pb(ret);
    }

    rep(i,ans.size()){
        cout << siz <<  " ";
        rep(j, ans[i].size()){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
