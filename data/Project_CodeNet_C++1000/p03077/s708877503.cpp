#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LI list<int>
#define vct vector
#define vi vct<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vct<vi>
#define vll vct<ll>
#define vvll vct<vll>
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ff first
#define ss second
#define bg begin()
#define ft cout<<"for test"<<endl;
#define read(v,a,n) for(int i=a; i<n; i++)cin>>v[i];
#define pi 2*acos(0.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test,cs=1;cin>>test;while(test--)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define mod 1000000007
int main()
{
    FIO;

    ///freopen("in.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ll n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    ll cnt=0,mn=a;
    cnt = (n%a==0)?n/a:(n/a)+1;
    if(b>=mn)cnt++;
    else {cnt  = (n%b==0)?(n/b)+1:(n/b)+2;mn =b;}
    if(c>=mn)cnt++;
    else {cnt = (n%c==0)?(n/c)+2 : (n/c)+3; mn=c; }
    if(d>=mn)cnt++;
    else {cnt = (n%d==0)?(n/d)+3 : (n/d)+4 ; mn=d;}
    if(e>=mn)cnt++;
    else {cnt = (n%d==0)?(n/e)+4 : (n/e)+5;}
    cout<<cnt<<endl;
}
