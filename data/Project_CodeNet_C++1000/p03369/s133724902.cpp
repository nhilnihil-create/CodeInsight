#include <iostream>
#include <string>
#include <algorithm>
int main() {
  std::string topping;
  std::cin >> topping;
  int total_price = 700;
  int n_topping = std::count(topping.begin(), topping.end(), 'o');
  total_price += 100 * n_topping;
  std::cout << total_price;
}
