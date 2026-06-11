////////////////////////// Author
////////////////////////// Nasim Hossain Rabbi
////////////////////////// JU-CSE28
////////////////////////// CF - imnasim3.1415
////////////////////////// UVA - imnasim3.1415
////////////////////////// Mail - imnasim3.1415@gmail.com
#include<bits/stdc++.h>
using namespace std;
#define sz size()
#define mk make_pair
#define clr clear()
#define B begin()
#define E end()
#define EM empty()
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
#define all(cont) cont.begin(),cont.end()
#define pb push_back
string en="\n";
string t="hello";
#define sqr(a) ((a) * (a))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define pi 3.1415926535897932384626433832795
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define vp(vi,x) cin>>x; vi.pb(x);
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
typedef long long LL;
typedef unsigned long long ULL;
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,c=0;
    while(cin>>n)
    {
        vi a,aa;
        l=0,s=0;
        a.pb(0);
        rep(i,n)
        {
            cin>>x;
            a.pb(x);
            l=abs(l-x);
            s+=l;
            l=x;
        }
        a.pb(0);
        l=abs(l-0);
        s+=l;
//        rep(i+1,n)
        for(i=1;i<n+1;i++)
        {
            x=s-(abs(a[i]-a[i-1])+abs(a[i+1]-a[i]));
            x+=abs(a[i+1]-a[i-1]);
            cout<<x<<en;
        }
    }
}

