#include<bits/stdc++.h>
using namespace std;


int main(){
  int N,Y;
  cin >> N >> Y;
  int A = 0,B= 0,C = 0;
  int ans = -1;
  int k;
  for(int i = 0;i <= N;i++){
    for(int j = 0;j <= N-i;j++){
      k = N - i -j;
      if(k >=0){
      if(10000*i + 5000*j + 1000*k == Y){
        A = i;
        B = j;
        C = k;
        ans = 1;
        break;
      }
      }
    }
  }
  if(ans == -1){
	A = -1;
    B = -1; 
    C = -1;
  }
  cout << A << " " << B << " " << C << endl;
}
  
		