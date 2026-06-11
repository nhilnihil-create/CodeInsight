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
ll m,k;
vector<ll> a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m>>k;
    if(k>=pow(2,m)){
        return cout<<-1<<"\n",0;
    }
    if(m==0){
        if(k==0){
            return cout<<0<<" "<<0<<"\n",0;
        }
        return cout<<-1<<"\n",0;
    }
    if(m==1){
        if(k==0){
            return cout<<0<<" "<<0<<" "<<1<<" "<<1<<"\n",0;
        }
        return cout<<-1<<"\n",0;
    }
    cout<<k<<" ";
    for(int i=0;i<pow(2,m);i++){
        if(i==k)continue;
        cout<<i<<" ";
    }
    cout<<k<<" ";
    for(int i=pow(2,m)-1;i>=0;i--){
        if(i==k)continue;
        cout<<i<<" ";
    }
    cout<<"\n";
    //1から2のn乗-1のxorは0 (2*kと2*k+1のxorは1->1が偶数個できる->0)
}  

