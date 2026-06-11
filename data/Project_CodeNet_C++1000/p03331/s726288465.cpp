#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;cin >> N;
  if (N==100000 || N==10000 || N==1000 || N==100 || N==10) cout << 10 << endl;
  else cout << N/10000+(N-N/10000*10000)/1000
			+(N-N/1000*1000)/100
			+(N-N/100*100)/10
			+(N-N/10*10)
			<< endl;
  
}