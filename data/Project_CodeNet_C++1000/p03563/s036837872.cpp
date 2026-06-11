#include <bits/stdc++.h>
using namespace std;

int main() {
  int nowRating,nextRating;
  cin >> nowRating;
  cin >> nextRating;
  
  int performance = nextRating + ( nextRating - nowRating );
  cout << performance << endl;
}