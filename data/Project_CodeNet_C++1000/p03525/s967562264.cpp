#include <iostream>
#define llint long long

using namespace std;

llint n;
llint d[13];
bool used[25];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  d[0] = 1;
  llint x;
  for(int i = 1; i <= n; i++){
    cin >> x;
    d[x]++;
  }
  for(int i = 0; i <= 12; i++){
    if(d[i] >= 3){
      cout << 0 << endl;
      return 0;
    }
  }
  if(d[0] >= 2 || d[12] >= 2){
    cout << 0 << endl;
    return 0;
  }

  llint N = 1 << 13, ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j <= 24; j++) used[j] = false;
    for(int j = 0; j <= 12; j++){
      if(j == 0 || j == 12){
        if(d[j]) used[j] = true;
      }
      else{
        if(d[j] >= 2) used[j] = used[24-j] = true;
        if(d[j] == 1){
          if(i & (1<<j)) used[j] = true;
          else used[24-j] = true;
        }
      }
    }
    used[24] = true;

    llint mn = 25, pre = 0;
    for(int j = 1; j <= 24; j++){
      if(used[j]){
        mn = min(mn, j-pre), pre = j;
      }
    }
    ans = max(ans, mn);
  }
  cout << ans << endl;

  return 0;
}
