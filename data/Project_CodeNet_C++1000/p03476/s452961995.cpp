//// Journey of Harry Singh from Diploma in Cse to Red Coder of India.///////////////////////////////////////////////////
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
int main(){

int p[100005]={0};
for(int i=2;i<=100005;i++)
{
	int d=0;
	if(isPrime(i) && isPrime(((i+1)/2)))d++;;
	p[i]=d+p[i-1];
}

int q;cin>>q;
while(q--)
{    
	int l,r;
	cin>>l>>r;
	cout<<p[r]-p[l-1]<<"\n";
}








}