#include<bits/stdc++.h>
using namespace std;

int main(void){
  int antena[5];
  int k, cnt = 0;
  for(int i = 0; i < 5; i++)
    cin >> antena[i];
  cin >> k;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(antena[i] < antena[j] && antena[j] - antena[i] <= k)
      cnt++;
    }
  }
  if(cnt == 10) cout << "Yay!" << "\n";
  else cout << ":(" << "\n";
  return 0;
}
