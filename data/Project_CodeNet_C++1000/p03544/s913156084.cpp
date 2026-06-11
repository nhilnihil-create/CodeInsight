#include <bits/stdc++.h>
using namespace std;

int main() {
	 int N;
	 cin >> N;
	 long long a=2, b=1, ans=0;
	 if (N==1){
	     cout << 1 << endl;
	     return 0;
	 }
	 for (int i=1; i<N; i++){
	     ans=a+b;
	     a=b;
	     b=ans;
	 }
	 cout << ans << endl;
}
