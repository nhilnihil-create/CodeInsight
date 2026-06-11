#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, sum=0;
    cin >> K;
    int N = K;
    while (true){
      		sum += N%10;
      		N = (N-N%10)/10;
      		if (N==0) break;
    }
   
    if (K%sum==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}