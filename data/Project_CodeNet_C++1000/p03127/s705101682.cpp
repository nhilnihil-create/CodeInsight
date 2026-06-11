#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
 
int main() {
    int n;cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int k = 0;
    for(int i = 0;i<n-1;i++){
       k = gcd(a[i],a[i+1]);
       a[i+1] = k;
       //cout<<a[i]<<endl;
    }
    cout<<k;
    return 0;
}