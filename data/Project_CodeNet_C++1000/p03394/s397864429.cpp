#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;
int simple_case[] = {2, 5, 63, 70, 140, 210, 280, 350, 420, 490};

int main(int argc, char const *argv[]) {
  ll N, S=0;
  std::cin >> N;
  if(N<10){
    for(int i=0;i<N;i++){
      std::cout << simple_case[i] << (i==N-1?"":" ");
    }
    std::cout <<'\n';
    return 0;
  }
  std::vector<int> next;
  for(int i=1;i<15001;i++) next.push_back(i*2);
  for(int i=1;i<10001;i++) if(i%2!=0) next.push_back(i*3);
  sort(next.begin(), next.end());
  for(int i=0;i<N;i++) S+=next[i];
  switch(S%6){
    case 2: next[4] = 30000;
            break;
    case 3: next[5] = 30000;
            break;
    case 5: next[5] = 29998;
            break;
  }
  //S=0;
  for(int i=0;i<N;i++) {
    std::cout << next[i] << (i==N-1?"":" ");
    //S+=next[i];
  }
  //std::cout << S%6 << '\n';
  std::cout << '\n';
  return 0;
}
