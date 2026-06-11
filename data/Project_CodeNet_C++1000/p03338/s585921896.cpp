#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int power(int a,int b)
{
    if(b==0)
        return 1;
    long long int k=power(a,b/2);
    if(b%2==0)
        return ((k%M)*(k%M))%M;
    else
        return ((k%M)*(k%M)*(a%M))%M;
}
long long int fact(long long int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return ((n%M)*(fact(n-1)%M))%M;

}
int div(int n)
{  int c=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
          if(n/i==i)
            c++;
          else
            c+=2;
        }

    }

    
    return  c;
}
int func(int n)
{
    return (n*(n+1))/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   
     
   int n;
   cin>>n;
   string str;
   cin>>str;
   int cmax=0;
   
   for(int i=1;i<str.length();i++)
   {
      string s1,s2;
      s1=str.substr(0,i);
      s2=str.substr(i,str.length()-i);
      set<char> s3,s4;
      for(int j=0;j<s1.size();j++)
      {
        s3.insert(s1[j]);
      }
      for(int j=0;j<s2.size();j++)
      {
        s4.insert(s2[j]);
      }
      int c=0;
      for(auto x: s3)
      {
        auto p=s4.find(x);
        if(p!=s4.end())
            c++;
      }
      cmax=max(cmax,c);
   }
   cout<<cmax;




 return 0;
}






