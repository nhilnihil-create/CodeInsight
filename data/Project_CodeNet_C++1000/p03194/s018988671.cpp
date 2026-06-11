#include<bits/stdc++.h>
#define ll long long int
using namespace std;  
// A function to print all prime factors of a given number n 
ll primeFactors(ll p,ll n) 
{ 
    // Print the number of 2s that divide n 
    ll cnt_2=0;
    while (p%2 == 0) 
    { 
        //printf("%d ", 2); 
        p = p/2;
		cnt_2++; 
    } 
    //cout<<cnt_2<<endl;
  	ll ans1=(cnt_2/n);
  	//cout<<ans1<<endl;
  	if(cnt_2!=0)
  	ans1=pow(2,ans1);
  	//cout<<ans1<<endl;
  	ll ans=ans1;
  	cnt_2=0;
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2)
	if(ans==0)
	ans=1; 
    for (ll i = 3; i <= sqrt(p); i = i+2) 
    { 
    	cnt_2=0;
        // While i divides n, print i and divide n 
        while (p%i == 0) 
        { 
            //printf("%lld ", i); 
            p = p/i;
			cnt_2++; 
        } 
        //cout<<i<<" "<<cnt_2<<endl;
        ans*=pow(i,cnt_2/n);
    } 
  	if (p > 2) 
        {
        	ans*=pow(p,1/n);
		}
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    return ans;
} 
  
/* Driver program to test above function */
int main() 
{ 
	ll n,p;
	cin>>n>>p;
    cout<<primeFactors(p,n); 
    return 0; 
}