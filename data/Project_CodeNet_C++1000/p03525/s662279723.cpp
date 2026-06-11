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
int n;
vector<int> a;
map<int,int> m;
vector<int> va(24,false);//確定の点
int count(){
    int mi=25;
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            if(va[i]&&va[j]&&i!=j){
                int d=min(abs(i-j),24-abs(i-j));
                chmin(mi,d);
            }
        }
    }
    return mi;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
        m[temp]++;
    }
    m[0]++;
    if(m[0]>=2) return cout<<0<<"\n",0;
    va[0]=true;
    vector<int> v;//2択の点
    for(int i=1;i<12;i++){
        if(m[i]==1)v.push_back(i);
        else if(m[i]==2) va[i]=true,va[24-i]=true;
        else if(m[i]>=3)return cout<<0<<"\n",0;
    }
    int ans=0;
    if(m[12])va[12]=true;
    if(m[12]>=2)return cout<<0<<"\n",0;
    for(int i=0;i<(1<<v.size());i++){
        for(int j=0;j<v.size();j++){
            if(i&(1<<j))va[v[j]]=true,va[24-v[j]]=false;
            else{
                va[v[j]]=false,va[24-v[j]]=true;
            }
        }
        chmax(ans,count());
    }
    chmax(ans,count());
    cout << ans << "\n";
}

