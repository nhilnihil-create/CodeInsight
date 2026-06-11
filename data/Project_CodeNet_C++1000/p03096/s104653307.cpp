#include<iostream>
 using namespace std;
 const long long mod = 1e9 + 7;
 int a[200005], b[200005], c[200005];
 long long num[200005];
int main() 
{
	 int n, k = 1;
	 cin >> n;
     for (int i = 1; i <= n; i++) 
		 scanf("%d", &a[i]);
	 c[1] = a[1];
	 int t = 1;
	 for (int i = 2; i <= n; i++) 
	 {
		 if (a[i] != c[t])
			 c[++t] = a[i];
	
	  }
	  num[0] = 1;
	  for (int i = 1; i <= t; i++) {
		   if (b[c[i]])
			   num[i] = (num[i - 1] + num[b[c[i]]]) % mod;
		   else num[i] = num[i - 1];
		       num[i] %= mod;
		       b[c[i]] = i;
		
	  }
	  cout << num[t] << endl;
	  return 0;
}