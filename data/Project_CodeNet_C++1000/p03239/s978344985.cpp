#include <iostream>
using namespace std;
int main()
{
  int n,t;
  int menor = 1001;
  cin >> n;
  cin >> t;
  while(n-- > 0){
  	int a,b;
  	cin >> a;
  	cin >> b;
  	if(b <= t){
  	    if(a <= menor){
  	        menor = a;
  	    }
  	}    
  }
    (menor == 1001) ? cout << "TLE" : cout << menor;
  return 0;
}