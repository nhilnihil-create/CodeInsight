#include<bits/stdc++.h>
using namespace std;
 
int reve(int x)
{
  int m;
  	m = 0;
	m += (x % 10) * 10000;
	x /= 10;
	m += (x % 10) * 1000;
	x /= 10;
	m += (x % 10) * 100;
	x /= 10;
	m += (x % 10) * 10;
	x /= 10;
	m += (x % 10) * 1;
return m;
}
 
int main(void)
{
  int A, B, s;
  cin >> A >> B;
  s = 0;
  for(int i = A; i <= B; i++){
  	if(i == reve(i)){
    s++;
    }
  }
  cout << s << endl;
}