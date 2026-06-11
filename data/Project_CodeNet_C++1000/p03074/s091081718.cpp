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
    
            int k,n,z=0,ans=0,start=-1,end=-1,f=0,c=0;
            cin>>n>>k;
            vector<int> start_index;
string s;
            cin>>s;
            start=0,end=0;
            
            for(int i=1;i<n;i++)
            {
              if(s[i]=='1' && s[i-1]=='0')
              {
                start_index.push_back(i);
              }
              else if(i==1 && s[i-1]=='1')
              start_index.push_back(0);
            }
            z=0;
            if(s[n-1]=='0')
            start_index.push_back(n);

if(k-1<start_index.size())
{
  z=0;
  end=start_index[k-1];
  z+=end;
  while(end<n && s[end]=='1')
  {
    z++;
    end++;
  }
  ans=max(ans,z);
}            

for(int i=0;i<start_index.size();i++)
{
  if(start_index[i]!=n)
  {
   start=start_index[i];
   end=-1;
   z=0;
   if(i+k<start_index.size())
   {
     end=start_index[i+k];
   
     z+=(end-start);
     while(s[end]=='1' && end<n)
     {
       z++;
       end++;
     }
     ans=max(ans,z);
   }
   else
   {
     ans=max(ans,n-start);
   }
  }
}

//cout<<start_index.size();
if(k>=start_index.size())
ans=n;

cout<<ans;
            cout<<"\n";
           
            
            
            
return 0;
}
            
            
            
            