#include <iostream>

using namespace std;

int main() {

  int n, l, s = 0, m = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> l;
    s += l;
    m = max(m, l);
  }
  if(m < s - m){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
