#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int before_rating = 0;
  int target_rating = 0;
  
  cin >> before_rating >> target_rating;
  double performance = 2 * target_rating - before_rating;
  
  cout << performance << endl;
}
