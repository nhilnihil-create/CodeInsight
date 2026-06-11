#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
  int n;
  cin >> n;
  for(int i = 0;i < n;i++) cin >> a[i];
  int flag[110] = {0};
  
  for(int i = 0;i < n;i++) flag[a[i]]++;
  int count = 0;
  for(int i = 0;i <= 100;i++){
    if(flag[i] > 0) count++;
  }
  
  cout << count << endl;
}
