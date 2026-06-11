
#include <bits/stdc++.h>
 
int main() {
  int currentRating, wantedRating;
  std::cin >> currentRating;
  std::cin >> wantedRating;
  
  int aimingPerformance = 2 * wantedRating - currentRating;
  
  std::cout << aimingPerformance;
}

