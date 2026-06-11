#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x,long long int y) 
{ 
    long long int res = 1;     // Initialize result 
  // x=x;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x); 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x);  // Change x to x^2 
    } 
    return res; 
}
long long int power(long long int x,long long int y,long long int m) 
{ 
    long long int res = 1;     // Initialize result 
   x=x%m;
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x)%m; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x)%m;  // Change x to x^2 
    } 
    return res; 
}
void primeFactors(int n)  
{  
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        cout << n << " ";  
}

long long int gcd(long long int a, long long int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 long long int lcm(long long int a, long long int b)  
 { 
     long long int temp;
    
    return (a*b)/gcd(a, b);  
 }
 
int main() {
  // freopen("input.txt","r",stdin);
    long long int n1,m1,t;
 //   cin>>t;
   t=1;
    while(t--)
    {
   long long int i,j;
 //long long int b[1000000];
 //set<long long int >s;
       long long int f=1,p=0,z,o=0;
       double pie=3.141592653589793238;
    long long int c=0,n,m,l=0,r=0,k,min1=10000000000000,max2=-100;
 cin>>n>>m>>k;
 long long int a[m];
 for(i=0;i<m;i++)
 cin>>a[i];
 sort(a,a+m);
 for(i=0;i<m;i++)
 if(a[i]>k)
 break;
 if(i==0&&i==n)
 cout<<0;
 else
 {
 	p=i;
 	l=i;
 	for(i=k-1;i>=0;i--)
 	{
 		if(p-1>=0&&i==a[p-1])
 		{
 			c=c+1;
 			p--;
		 }
 		
	 }
	 min1=min(min1,c);
	 c=0;
	 for(i=k+1;i<=n;i++)
	 {
	 	if(l<m&&i==a[l])
	 	{
	 		c=c+1;
	 		l++;
		 }
	 	
	 }
	 min1=min(min1,c);
 
 cout<<min1;
 }
 
 //vector<pair<long long int,long long int>>v;
 
    }
 return 0;
}
