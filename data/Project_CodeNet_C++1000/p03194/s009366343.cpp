#include<iostream>
#include <string.h>
#include <math.h> 
#include <algorithm>
#include<cstdlib>
typedef long long ll;
using namespace std;


int main()
{
    ll n,p,ans = 1;
    cin >> n >> p;

    for(ll i = 2; i*i <= p; i++)
    {
        //if(IsPrime(i) == true){
        int cnt = 0;
        while(p % i == 0)
        {
            cnt++; 
            p /= i;
        }  
        for(int j = 0; j < cnt/n; j++)
        {
            ans *= i;
        }  
        
    }
    if(n == 1) ans *= p;
    cout << ans << endl;
}