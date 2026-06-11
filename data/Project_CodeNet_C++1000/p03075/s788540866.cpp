#include<iostream>
using namespace std;

int main(){
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  int antennas[5] = {a, b, c, d, e};
  
  for(int i=0; i<4; i++){
    for(int j=i+1; j<5; j++){
      int dis = antennas[i]-antennas[j];
      dis = (dis < 0 ? -dis : dis);
      if(dis > k){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  
  cout << "Yay!" << endl;
  
  return 0;
}