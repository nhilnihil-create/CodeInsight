//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF =1e9;
const ll LINF=1e18;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a / gcd(a, b)*b;}
int n, m;
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    vector<vector<int> >v(n,vector<int>(m));
    bool check=true;
    int now=0;
    int j=1;
    if(s[n-1]=='1')return cout<<-1<<"\n",0;
    if(s[0]=='0')return cout<<-1<<"\n",0;
    for(int i=0;i<(n-1)/2;i++){
        if(s[i]!=s[n-2-i])return cout<<-1<<"\n",0;
    }
    for(int i=0;i<n;i++){
        if(j>=n)break;
        if(check){
            if(s[i]=='1'){
                v[now].push_back(j);
                now=j;
                j++;
            }
            else{
                v[now].push_back(j);
                check=false;
                j+=1;
            }
        }
        else{
            if(s[i]=='1'){
                v[now].push_back(j);
                now=j;
                j++;
                check=true;
            }
            else{
                v[now].push_back(j);
                check=false;
                j++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<i+1<<" "<<v[i][j]+1<<"\n";
        }
    }
}

