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
  int A, B;
  cin >> A >> B;

  int a = 0, b = 0, c = 0;
  for(int i = 0; i < N; i++){
    int p;
    cin >> p;
    if(p <= A) a++;
    else if(A < p && p <= B) b++;
    else c++;
  }

  cout << min(min(a, b), c) << endl;
  return 0;
}
