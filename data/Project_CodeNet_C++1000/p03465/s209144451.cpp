#include<bits/stdc++.h>
using namespace std;
bitset<2000007>f;
int n , x , sum;
int main () {
	cin >> n;
	f[0] = 1;
   for(int i =  1 ; i <= n ; i ++){
   	scanf("%d" , &x);
   	f |= f << x;
   	sum += x;
   }
   for(int i = (sum + 1) >> 1 ; i <= sum ; i ++){
   	if(f[i]){
   		cout << i << endl;
   		return 0;
	   }
   }
   return 0;	
}