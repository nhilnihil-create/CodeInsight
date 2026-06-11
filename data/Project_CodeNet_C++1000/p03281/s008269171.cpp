#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> eratos(200+1, 0);
  for(int i=2; i<=200; i++)
    if(eratos[i] == 0){
      eratos[i] = i;
      for(int j=2; i*j<=200; j++)
        if(eratos[i*j] == 0)  eratos[i*j] = i;
    }

  int n;  cin >> n;
  int ans = 0;
  for(int i=3; i<=n; i+=2){
    int yaku = 1, nowi = i;
    do{
      int cnt = 0, d = eratos[nowi];
      while(nowi%d == 0){
        nowi /= d;
        cnt++;
      }
      yaku *= (cnt+1);
    }while(nowi != 1);
    if(yaku == 8)  ans++;
  }
  cout << ans << endl;
  return 0;
}
