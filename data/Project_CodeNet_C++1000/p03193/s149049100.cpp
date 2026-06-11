#include <iostream>
using namespace std;

int main(void){
  long n, h, w;
  cin >> n >> h >> w;
  long a[n], b[n];
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int num = 0;
  for(int i = 0; i < n; i++){
    if(a[i] >= h && b[i] >= w) num++;
  }
  cout << num << endl;
  return 0;
}
