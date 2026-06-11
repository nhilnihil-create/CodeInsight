#include <iostream>
#include <algorithm>
using namespace std;
const int INF=1 << 29;

int main(){

  //initialization
  int N;
  int T, A;
  int min = INF;
  int ans = 0; 

  //input 
  cin >> N;
  cin >> T >> A;
  int H[N]; 
  int temparature[N];
  
  T*=1000;
  A*=1000;

  //solver
  for(int i=0; i<N; i++){
    cin >> H[i];
    temparature[i] = abs(A - (T - H[i] * 6));

    if(min > temparature[i]){
	min = temparature[i];
   	ans = i+1;
    }
    //cout << temparature[i] << " ";
  }
 // cout << "\n";
  cout << ans << "\n"; 
}
