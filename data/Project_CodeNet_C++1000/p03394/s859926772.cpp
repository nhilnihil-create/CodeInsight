#include<iostream>
#include<vector>

using ll = long long;
const ll INF = (ll)1e18;

template <typename Head> void print(Head&& head) { std::cout << head << std::endl; }
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail)
{
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...); // or print(tail...);
}

template <typename Iterator> void printVec(Iterator begin, Iterator end)
{
  Iterator it = begin;
  std::cout << *it;
  it++;
  for (; it != end; it++) { std::cout << " " << *it; }
  std::cout << std::endl;
}

int main()
{
  ll N;
  std::cin >> N;

  if(N == 3){
    print(2, 5, 63);
  }else if(N == 4){
    print(2, 3, 4, 9);
  }else if(N == 5){
    print(2, 3, 4, 6, 9);
  }else{
    ll sum = 0LL;
    ll idx8 = 0LL;
    ll idx9 = 0LL;
    std::vector<ll> vans(N);
    std::vector<ll> va(4);
    va[0] = 2LL;
    va[1] = 3LL;
    va[2] = 4LL;
    va[3] = 6LL;
    for (ll i = 0; i < N; i++) {
      vans[i] = 6 * (ll)(i / 4) + va[i % 4];
      sum += vans[i];
      if (vans[i] == 8) idx8 = i;
      if (vans[i] == 9) idx9 = i;
    }
    ll mod_num = sum % 6;
    if (mod_num == 2) {
      vans[idx8] = 6 * (ll)(1 + N / 4);
    } else if (mod_num == 3) {
      vans[idx9] = 6 * (ll)(1 + N / 4);
    } else if (mod_num == 5) {
      vans[idx9] = 6 * (ll)(N / 4) + 4;
    }
    printVec(vans.begin(), vans.end());
  }
  return 0;
}
