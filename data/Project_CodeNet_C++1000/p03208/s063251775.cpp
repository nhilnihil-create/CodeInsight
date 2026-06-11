#include<bits/stdc++.h>
using namespace std;
int a[100009],minx = (1 << 30);
int main(){
      // #ifndef ONLINE_JUDGE
      //  // for getting input from input.txt
      //  freopen("input.txt", "r", stdin);
      //  // for writing output to output.txt
      //  freopen("output.txt", "w", stdout);
      // #endif
	   int n,k;
     cin>>n>>k;
     for (int i = 0; i < n; ++i)
     {
       cin>>a[i];
     }
     sort(a,a+n);
     for (int i = 0; i <= n-k; ++i)
     {
       minx = min(minx, (a[i+k-1] - a[i]));
     }
     cout<<minx;
	return 0;
}
