#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,max=40,current=0;
  cin >> N;
  for(int i=1;i<N+1;i++){
    current=0;
    int j;
    cin >> j;
    while(j%2==0){
	  j/=2;
      current++;
    }
    if(current<max)
      max=current;
  }
  cout << max << endl;
}
   