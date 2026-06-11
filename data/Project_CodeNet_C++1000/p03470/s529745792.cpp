#include <iostream>
#include <set>

int main () {

  int N;
  int d[110];

  std::cin >> N;
  
  for(int i = 0; i < N; i++) {
    std::cin >> d[i];
  }
  
  std::set<int> associative_array;
  for(int i = 0; i< N; i++) {
    associative_array.insert(d[i]);
  }
  
  std::cout << associative_array.size() << std::endl;
  

}