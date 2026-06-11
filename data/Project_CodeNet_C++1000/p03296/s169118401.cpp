# include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int ans = 0;
  int color[n+5];
  for(int i=0; i<n; i++) cin >> color[i];

  int l = 0, r = 0;
  while(l < n){
    while(r+1 < n && color[l] == color[r+1]) r++;
    ans += (r-l+1)/2;
    l = r+1;
    r = l;
  }
  cout << ans << endl;
  return 0;
}