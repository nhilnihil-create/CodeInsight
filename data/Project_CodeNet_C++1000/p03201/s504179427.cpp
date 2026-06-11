//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
ll n;
vector<ll> a;
vector<ll> two;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll temp=1;
    while(true){
        two.push_back(temp);
        if(temp>10000000000)break;
        temp*=2;
    }
    map<ll,ll> m;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        m[temp]++;
    }
    sort(ALL(a),greater<ll>());
    for(int i=0;i<n;i++){
        ll tar;
        if(!m[a[i]])continue;
        for(int j=0;j<two.size();j++){
            if(a[i]<two[j]){
                tar=two[j]-a[i];
                break;
            }
        }
        if(m[tar]>0&&tar!=a[i]){
            ans++;
            m[tar]--;
        }
        if(tar==a[i]&&m[tar]>1){
            ans++;
            m[tar]--;
        }
        m[a[i]]--;
    }
    cout << ans << "\n";
}

