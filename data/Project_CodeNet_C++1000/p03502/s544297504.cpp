#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
   	int N, c=0;
  	cin >> N;
    int K = N;
    while (true){
    	c += (N%10);
    	N -= (N%10);
      	if (N==0) break;
    	N /= 10;
       }
   if (K%c == 0) cout << "Yes" << endl;
   else cout << "No" << endl;
}