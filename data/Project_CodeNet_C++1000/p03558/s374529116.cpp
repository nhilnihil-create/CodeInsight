#include <iostream>
#include <vector>
#include <stack>
#include <utility>

int main(){
  int K;
  std::cin >> K;

  std::vector<int> searched(K);
  std::stack<long long> current, next;
  current.push(1);
  long long length=1;
  bool found = false;
  while(true){
    while(current.size() > 0){
      long long n = current.top();
      current.pop();
      searched[n] = 1;
      if(n == 0){
        found = true;
        break;
      }
      long long n10 = (10*n)%K, n1 = (n+1)%K;
      if(searched[n10] == 0) current.push(n10);
      if(searched[n1] == 0) next.push(n1);
    }
    if(found) break;
    length++;
    std::swap(current, next);
  }

  std::cout << length << std::endl;

  return 0;
}

