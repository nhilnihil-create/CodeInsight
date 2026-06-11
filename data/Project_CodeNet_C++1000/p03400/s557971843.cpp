#include <iostream>
using namespace std;
int main(){
  int N; cin >>N;
  int D,X; cin >> D >> X;
  int ans = X + N;
  for(int i = 0; i < N; i++){
	int a; cin >>a;
    ans += (D - 1) / a;
  }
  cout << ans << endl;
}