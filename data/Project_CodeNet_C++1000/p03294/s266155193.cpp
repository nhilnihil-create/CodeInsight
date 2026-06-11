#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[99999];
int main()
{
    int i,n,k;
cin >> n;
int ans = -n;
    for(i=0;i<n;i++){
    cin>>a[i];
       ans += a[i];
    }
   cout << ans;
}