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
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    int n=s.size();
    map<char,int> m;
    string sx="";
    vector<int> sum;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]!='x'){
            sx+=s[i];
            sum.push_back(count);
            count=0;}
        else{
            count++;
        }
        m[s[i]]++;
    }
    sum.push_back(count);
    for(int i=0;i<sx.size()/2;i++){
        if(sx[i]!=sx[sx.size()-1-i])return cout<<-1<<"\n",0;
    }
    int ans=0;
    /*
    for(int i=0;i<sum.size();i++){
        cout<<sum[i]<<" ";
    }
    cout<<"\n";
    */
    if(sum.size()%2){
        for(int i=0;i<sum.size()/2;i++){
            ans+=abs(sum[i]-sum[sum.size()-1-i]);
        }
        //ans+=sum[sum.size()/2]%2;
    }
    else{
        for(int i=0;i<sum.size()/2;i++){
            ans+=abs(sum[i]-sum[sum.size()-1-i]);
        }
    }
    cout << ans << "\n";
}

