#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int s=0;
  for(int x=1; x<=n; x+=2){
    int k=0;
    for(int i=1; i<=n; i++){
      if (x%i==0) k++;
    }
    if (k==8) s++;
  }
  cout << s << endl;
}