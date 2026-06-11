#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N];
  for(int i = 0; i < N; i++){
    cin >> a[i];
    a[i] *= N;
  }

  int ave = 0;
  for(int i = 0; i < N; i++) ave += a[i];
  ave /= N;

  int ind = 0;
  int mn = 1000000000;
  for(int i = 0; i < N; i++){
    if(abs(a[i] - ave) < mn){
      mn = abs(a[i] - ave);
      ind = i;
    }
  }

  cout << ind << endl;
  return 0;
}
