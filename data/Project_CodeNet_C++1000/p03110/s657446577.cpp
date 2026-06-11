#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
#define lp1(i,n) for(int i=0;i<n;i++)
#define lp2(i,n) for(int i=1;i<=n;i++)
#define pi cosa(-1)
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
ll gcd(ll a,ll b)
{
	while(b ^= a ^= b ^= a = a % b);
	return a;
}
std::string s;
void cin_space()
{

    std::getline(std::cin, s);
}
void sortstring(string &str)
{
   sort(str.begin(), str.end());
}
bool check_prime(ll n)
{
    ll q=sqrt(n)+1;
    for(int i=2;i<q;i++)
        if(n%i==0)
            return 0;
    return 1;
}
ll ceil(ll n,ll k){
    return (n+k-1)/k;
}
#define i64 long long
i64 M;
i64 F(i64 N,i64 P)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		i64 ret=F(N,P/2);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(F(N,P-1)%M))%M;

}
ll m;
ll bigmod(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll ret=bigmod(n,p/2);
        return ((ret*m)*(ret*m))%m;
    }
    else
        return ((n%m)*(bigmod(n,p-1)))%m;
}
void solution()
{
    ll n;
    double sum=0.0,x;
    string s;
    cin>>n;
    map<string,int>mp;
    for(int i=1;i<=n;i++){
        cin>>x>>s;
        if(s=="JPY"){
            sum+=x;
        }
        else
        {
            sum+=380000.0*x;
        }

    }
    printf("%lf\n",sum);
    //cout<<sum<<endl;
}

int main()
{   /*ll t;
    cin>>t;
    while(t--){*/
        solution();
    //}

    return 0;
}
