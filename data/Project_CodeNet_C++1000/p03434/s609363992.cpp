#include <iostream>
#include <vector>

int main(void){
  int n, a, max=0, ans=0, i;
  std::cin >> n;
  std::vector<int> card(n), scard(n);
  for(i=0; i<n; i++){
    std::cin >> card.at(i);
    if(card.at(i) > max) max = card.at(i);
  }
  std::vector<int> count(max+1);
  for(i=0; i<n; i++) count.at(card.at(i))++;
  for(i=0; i<max; i++) count[i+1] += count[i];
  for(i=n-1; i>=0; i--){
    scard.at(count.at(card.at(i))-1) = card.at(i);
    count.at(card.at(i))--;
  }
  for(i=n-1; i>=0; i--){
    if(i%2 == (n-1)%2) ans += scard.at(i);
    if(i%2 != (n-1)%2) ans -= scard.at(i);
  }
  std::cout << ans << std::endl;
  return 0;
}