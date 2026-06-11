#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  for(int i = 0;i < 30;i++){
    for(int j = 0;j < 30;j++){
      if(4*i + 7*j == n){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}


