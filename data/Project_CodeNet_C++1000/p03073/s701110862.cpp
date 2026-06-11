#include<bits/stdc++.h> 
using namespace std; 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forp(i,a,b) for (int i = a; i <b; i++)
#define forn(i,a,b) for (int i = a; i >b; i--)
#define mod 1000000007
#define MAX 50
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;


long long int fact(long long int n)
{
  if(n==0 || n==1)
  return 1;
  else
  return (n*fact(n-1)%mod)%mod;
}

int prime(long long int n)
{
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      return 0;
    }
  }
  return 1;
}

long long int gcd(long long int a,long long int b)
{
  if(a==0)
  return b;
  else
  return gcd(b%a,a);
}

long long int lcm(long long a,long long b)
{
    return (a*b)/gcd(a,b);
}

int check_palin(string s)
{
  string str=s;
  reverse(str.begin(),str.end());
  if(str==s)
  return 1;
  else 
  return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
            int k,n,z=0;
string s;
            cin>>s;
k=0,z=0;
int f=0;
n=s.size();

for(int i=0;i<n;i++)
{
  if(f==0)
  {
    if(s[i]=='1')
    {
      k++;
    }
    f=1;
  }
  else
  {
    if(s[i]=='0')
    k++;
    f=0;
  }
}
f=1;
for(int i=0;i<n;i++)
{
  if(f==0)
  {
    if(s[i]=='1')
    {
      z++;
    }
    f=1;
  }
  else
  {
    if(s[i]=='0')
    z++;
    f=0;
  }
}
 cout<<min(z,k);
            cout<<"\n";
           
            
            
            
return 0;
}
            
            
            
            