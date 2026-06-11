#include<bits/stdc++.h>
using namespace std;

#define     bip(a)         __builtin_popcount(a)
#define     ull            unsigned long long
#define     ll             long long
#define     u              unsigned
#define     pb             push_back
#define     pf             push_front ///for list
#define     mp             make_pair
#define     is             insert
#define     ff             first
#define     ss             second
#define     vi             vector<int>
#define     vl             vector<ll>
#define     si             set<int>
#define     sl             set<ll>
#define     li             list<int>
#define     pii            pair<int,int>
#define     pll            pair<ll,ll>
#define     mii            map<int,int>
#define     mll            map<ll,ll>
#define     ma             INT_MAX
#define     mi             INT_MIN
#define     mod            1000000007
#define     pi             3.14159265359
#define     e              2.71828182846
#define     inf            1000000000000000LL
#define     all(x)         x.begin(), x.end()
#define     lb(a,b,c)      lower_bound(a,a+b,c)-a
#define     ub(a,b,c)      upper_bound(a,a+b,c)-a
#define     lbv(a,c)       lower_bound(all(a),c)-a.begin()
#define     ubv(a,c)       upper_bound(all(a),c)-a.begin()
#define     srt1(a,b)      sort(a,a+b)
#define     srt2(a,b)      sort(a,a+b,greater<int>())
#define     gcd(a,b)       __gcd(a,b)
#define     lcm(a,b)       (a*(b/gcd(a,b)))
#define     harmonic(n)    0.57721566490153286l+log(n)
#define     mem(a, b)      memset(a, b, sizeof(a))

///s.lower_bound(a),s.upper_bound(a), for set
///nCr(x, y) = nCr(x-1, y-1) + nCr(x-1, y)
///factorial digit   ((n * log10(n / e) +log10(2 * pi * n) /2.0));

int main()
{
	/*int n,q,l,r,ac=0;
	string str;
	cin>>n>>q>>str;
	int pre[n+5];
	mem(pre,0);
	for(int i=0;i<n;){
		if(str[i]=='A'&&str[i+1]=='C'){
			ac++;
			pre[i+2]=ac;
			pre[i+1]=ac-1;
			i+=2;
		}
		else{
			pre[i+1]=ac;
			i++;
		}
	}*/
	/*for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
	cout<<endl;*/
	/*while(q--){
		cin>>l>>r;
		cout<<pre[r]-pre[l]<<endl;
	}*/
	char ch;
	cin>>ch;
	if(ch=='A')cout<<"T\n";
	if(ch=='T')cout<<"A\n";
	if(ch=='G')cout<<"C\n";
	if(ch=='C')cout<<"G\n";
}
