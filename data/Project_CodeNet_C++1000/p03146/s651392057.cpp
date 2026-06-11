#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int f(int a){
  if (a%2==0){
    return a / 2;
  }else{
    return 3 * a + 1;
  }
}

int main(){
  int s, ans=1;
  vector<int> A;
  cin >> s;
  int a = s;
  A.push_back(a);
  while(f(a) <= 1000000){
    a = f(a);
    ans++;
    if (binary_search(A.begin(), A.end(), a)){
      printf("%d\n", ans);
      break;
    }
    A.push_back(a);
    sort(A.begin(), A.end());
  }
}
