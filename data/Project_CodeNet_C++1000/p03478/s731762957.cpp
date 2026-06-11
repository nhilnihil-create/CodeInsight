#include <bits/stdc++.h> 
#define ll long long int  
int sumof(int x)
{
    int sum =0 ;
    while(x!=0)
    {
        sum+=x%10; 
        x/=10; 
    } 
    return sum ;
}
using namespace std;
int main() {
    ll n,a,b ;
    cin >> n >> a >> b ; 
    ll sum =0;
    for(int i=1;i<=n;i++)
    {
        if(sumof(i)>=a && sumof(i)<=b) sum+=i;
    } 
    cout << sum << "\n";
    return 0;
}
