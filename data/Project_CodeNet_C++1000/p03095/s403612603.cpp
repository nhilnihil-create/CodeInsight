#include <bits/stdc++.h>

using namespace std;

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define pll pair<ll,ll>
#define pii pair<int,int>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }


int main(){
    ll n,ans=1;
    cin>>n;
    string s;
    cin>>s;
    vi a(26,0);
    pan(i,n) a[s[i]-'a']++;
    pan(i,26){
        ans=((ans)%INF*(a[i]+1)%INF+INF)%INF;
    }
    cout<<(ans-1+INF)%INF;
}
