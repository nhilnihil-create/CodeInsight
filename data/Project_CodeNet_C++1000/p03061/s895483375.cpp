#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false) , std::cin.tie(0) , std::cout.tie(0)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define ll long long
#define fi first
#define se second
#define pb push_back
#define debug(x) 			  cout << #x << ": " << x << endl
#define debug2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define debug3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define debug4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
using namespace std;
template<typename T>void read(T &res){bool flag=false;char ch;while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);
for(res=ch-48;isdigit(ch=getchar());res=(res<<1)+(res<<3)+ch - 48);flag&&(res=-res);}
template<typename T>void Out(T x){if(x<0)putchar('-'),x=-x;if(x>9)Out(x/10);putchar(x%10+'0');}

const int N = 2e5 + 10;
int n,a[N],per[N],suf[N];
int main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n){
		per[i] = __gcd(per[i-1],a[i]);
		suf[n - i + 1] = __gcd(suf[n - i + 2],a[n - i + 1]);
	}
	int ans = 1;
	rep(i,1,n) ans = max(ans, __gcd(per[i-1],suf[i+1]));
	cout << ans << '\n';
    return 0;
}

