#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define gcu getchar_unlocked
#define pc(x) putchar(x);
#define pcu(x) putchar_unlocked(x);
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void readint(ll &x)
    {
        bool neg=false;
        ll c;
        x =0;
        c=gc();
        if(c=='-')
        {
            neg = true;
            c=gc();
        }
        for(;(c>47 && c<58);c=gc())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

inline void writeInt (ll n)
{
    ll N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    if (N*(-1)>0){pc('-');rev=rev*(-1);N=N*(-1);}
    while ((rev % 10) == 0) { count++; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int main()
{
  SPEED;
  int n,k,i,s=0;
  cin>>n>>k;
  for(i=n;i>n-k;i--)
  {
      s=s+(i/k);
  }
  cout<<s<<"\n";
  return 0;
}
