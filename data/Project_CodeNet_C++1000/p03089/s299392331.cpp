#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[105];
int ans[105];
int main() {
  int n;
  cin >> n;
  string f;
  for (int i = 1; i <= n; i++){
    cin >> arr[i];
  }

  int r = n;
  int cntr = 1;
  while (r > 0){
    int flag = -1;
    for (int i = r; i >= 1; i--){
      if (arr[i] == i){
        flag = i;
        break;
      }
    }
    if (flag == -1){
      cout << "-1" << endl;
      return 0;
    }
    ans[cntr] = flag;
    cntr++;
    for (int i = flag; i < r; i++){
      arr[i] = arr[i+1];
    }
    r--;
  }

  for (int i = n; i >= 1; i--){
    cout << ans[i] << endl;
  }

}