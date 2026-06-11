#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int a,b,c,x;
   cin >> a >> b >> c >> x;
   //int c1=a*500,c2=b*100,c3=c*50;
   int ans=0;
   for(int i=0;i<=a;i++) {
	   for(int j=0;j<=b;j++) {
		   for(int k=0;k<=c;k++) {
				ans+=i*500+j*100+k*50==x;
		   }
	   }
   }
   cout << ans;
   return 0;
}


