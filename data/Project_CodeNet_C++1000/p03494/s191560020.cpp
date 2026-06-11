#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int evens[N];
  for(int i=0; i<N; i++)
    cin >> evens[i];
  int count=-1;
  int judgh = N;
  while(judgh==N){
  count++;
  judgh=0;
  for(int i=0; i<N; i++){
    if(evens[i]%2==0)
    	judgh++;
    evens[i]=evens[i]/2;
  }
  }
  cout << count << endl;
}