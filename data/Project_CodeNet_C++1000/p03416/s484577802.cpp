#include <bits/stdc++.h>
using namespace std;

int main() {
				    // *constraint*
  int A,B;    	    // 10000<=A<=B<=99999 
  				    // Enter an Integer
  cin  >> A >> B;
  int count = 0;
  int a,b,c,d,e;
  int tmp;
  int i = A;
  while (i <= B) {
    tmp = i;
    a = tmp % 10;
    b = (tmp /= 10) % 10;
    c = (tmp /= 10) % 10;
    d = (tmp /= 10) % 10;
    e = (tmp /= 10) % 10;
    
    if(a == e && b == d){
      count++;
    }
    i++;
  }
  cout << count << endl;
}
