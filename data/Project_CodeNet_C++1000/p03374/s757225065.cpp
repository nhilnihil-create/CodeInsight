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

ll N , C;
vector<ll> x,v;
ll le[1000005];//左に進む
ll leo[1000005];// 左に進んでから戻る// 時計回り
ll ri[1000005];// 右に進む
ll rio[1000005];// 右に進んでから戻る//反時計回り

void set(){
    // 進んでから原点に戻ったとき、得るエネルギーを全て計算
    ll now = 0 ;
    ll before = 0;
    ll beforeo = 0;
    //rio[0] = 0;
    //leo[0] = 0;
    rep(i,N){
        now += v[i];
        if((now -x[i]-x[i] )> beforeo)leo[i] = now - x[i] - x[i];
        else leo[i] = beforeo;
        if((now-x[i]) >= before) {le[i] = now-x[i]; before = now-x[i];}
        else le[i] = before;
    }
    now = 0;
    before = 0 ;
    beforeo = 0;
    for(ll i = N-1 ; i >= 0; i--){
        now += v[i];
        if((now - (C-x[i]) - (C-x[i])) > beforeo)rio[i] = now - (C-x[i]) - (C-x[i]);
        else rio[i] = beforeo;
        if((now-(C-x[i])) >= before){ri[i] = now - (C-x[i]); before = now - (C-x[i]) ;}
        else ri[i] = before;
    }
}

ll way1(){
    set();
    
    ll ans = 0;
    rep(i,N-1){//leの行くところ
        ll sum1, sum2;
        if(i == 0){
            sum1 = 0;
            sum2 = ri[0];
        }
        else{
            sum1= le[i] + rio[i+1];
            sum2 = leo[i] + ri[i+1];
            ans = max(ans, sum1);
            ans = max(ans, sum2);
        }
    }
    return ans;
}

vector<ll> useR;
map<ll,ll> sumle, sumri;


ll findR(ll  till){
    ll l = 0;
    ll r = useR.size();
    while((l+1) < r){
        ll m = (l+r)/2;
        if(useR[m] >= till){
            r = m;
        }
        else{
            l = m;
        }
    }
    if( till == 0) return useR[useR.size()-1];
    else return useR[l];
}


ll way2(){
    ll nowvalue, before;
    nowvalue = 0 ;  before = 0 ;
    rep(i,N){
        nowvalue+=v[i];
        ll su = nowvalue - x[i];
        if(su >= before){
            before = su;
            useR.pb(i);
        }
    }
    nowvalue = 0 ;
    rep(i,N){
        nowvalue += v[i];
        sumri[i] = nowvalue;
    }
    nowvalue = 0 ;
    for(ll i = N-1; i>0; i--){
        nowvalue += v[i];
        sumle[i] = nowvalue;
    }
    sumle[0] = 0;
    
    
    
    ll ans = 0;
    rep(i, N){
        //if(i == 0) continue;
        ll l = i;
        ll r = findR(l);
        ll ldi = C-x[l];
        if(l == 0) ldi = 0;
        ll ans1 = sumle[l]  + sumri[r] - ldi - x[r] - x[r];
        ll ans2 = sumle[l]  + sumri[r] - ldi - x[r] - ldi;
        
        ans1 = max(ans1, ans2);
        ans  = max(ans, ans1);
        
    }
    return ans;
}


// a------b
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);


    cin >> N >> C;
    x.pb(0);
    v.pb(0);
    rep(i,N){
        ll xi, vi ;
        cin >> xi >> vi ;
        x.pb(xi);
        v.pb(vi);
    }
    N ++;
    
    ll a = way1();
    ll b = way2();
    
    cout << max(a,b) << endl;

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
