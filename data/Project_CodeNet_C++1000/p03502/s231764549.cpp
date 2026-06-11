#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, c = 0;
    cin >> N;
 	int n= N;
    while (N /= 10 != 0)
    {
        c += N % 10;
        N /= 10;
    }
  
   if (n%c == 0) {
      cout << "Yes" <<endl;}
	else  {
    cout << "No"<< endl;}
 
}