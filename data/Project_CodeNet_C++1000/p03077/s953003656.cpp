#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll time[5];
  for(int i=0;i<5;i++){
    cin >> time[i];
  }
  sort(time,time+5);
  ll ans = 0;
  if(N%time[0]!=0) ans = N/time[0]+5;
  else ans = N/time[0] + 4;
  cout << ans << endl;
}
