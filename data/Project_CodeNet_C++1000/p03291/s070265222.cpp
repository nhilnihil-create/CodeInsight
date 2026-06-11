#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  = 3.141592653589793238463;
const int N = 1e5+10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}


// Main Code

int a[N], b[N], c[N], q[N];


ll ppow(ll x, ll y)
{
  ll res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%M;
    y = y >> 1;
    x = (x * x)%M;
  }
  return res;
}

ll mul(ll x, ll y)
{
  return (((x%M)*(y%M))%M);
}

int main()
{
	string s;
	cin>>s;
	int cnta, cntb, cntc, cntq;
	cnta = cntb = cntc = cntq = 0;
	rep(i, 0, s.length())
	{
		if(s[i] == 'A') cnta++;
		else if(s[i] == 'B') cntb++;
		else if(s[i] == 'C')cntc++;
		else cntq++;
		a[i] = cnta;
		b[i] = cntb;
		c[i] = cntc;
		q[i] = cntq;
	}
	ll ans = 0;
	int n = s.length() - 1;
	rep(i, 0, s.length())
	{
		if(s[i] == 'B' || s[i] == '?')
		{
			if(s[i] == 'B')
			{
				ll qa = q[i];
				ll qc = q[n] - q[i];
				ll na = a[i];
				ll nc = c[n] - c[i];
				ll totalq = qa + qc;
				ll total = mul(na, mul(nc, ppow(3, totalq)));
				total = (total + mul(qa, mul(nc, ppow(3, totalq-1)))) % M;
				total = (total + mul(qc, mul(na, ppow(3, totalq-1)))) % M;
				total = (total + mul(qa, mul(qc, ppow(3, totalq-2)))) % M;
				ans  = (ans + total) % M;
			}
			else if(s[i] == '?')
			{
				ll qa = q[i] - 1;
				ll qc = q[n] - q[i];
				ll na = a[i];
				ll nc = c[n] - c[i];
				ll totalq = qa + qc;
				ll total = mul(na, mul(nc, ppow(3, totalq)));
				total = (total + mul(qa, mul(nc, ppow(3, totalq-1)))) % M;
				total = (total + mul(qc, mul(na, ppow(3, totalq-1)))) % M;
				total = (total + mul(qa, mul(qc, ppow(3, totalq-2)))) % M;
				ans  = (ans + total) % M;
			}
		}
	}
	cout<<ans<<endl;
}

