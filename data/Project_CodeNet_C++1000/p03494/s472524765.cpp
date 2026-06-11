#include <bits/stdc++.h>
#include<iostream>
#define point complex<double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=1e5+10,mod=1e9+7;
ll inf=LONG_LONG_MAX;
int a[N];
int GCD(int a, int b) {
	if(b==0)
    	return a;
	else
    	return GCD(b, a%b);
}



int main()
{
  /* ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
   int n;
   ll ans=1e9+5;
   cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++){
    if(a[i]%2){
        cout<<0;
        return 0;
    }
    int x=0;
  while(a[i]%2==0){
        x++;

    a[i]/=2;
  }
      ans=ans=min(ans,1LL*x);
   }
   cout<<ans;

    return 0;
}
