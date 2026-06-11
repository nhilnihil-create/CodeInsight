#include <bits/stdc++.h>

int64_t simulate(uint64_t N, uint64_t Q, const std::string &s, const std::string &t, const std::string &d, int64_t i)
{
  for (uint64_t q = 0; q < Q; ++q) {
    if (s[i] == t[q]) {
      i += (d[q] == 'L') ? -1 : +1;
    }
    
    if (i < 0 || i >= N) { return i; }
  }
  return i;
}

int64_t search_left(uint64_t N, uint64_t Q, const std::string &s, const std::string &t, const std::string &d)
{
  int64_t left = 0, right = N;
  
  while (right - left > 1) {
    int64_t mid = (left + right) >> 1;
    int64_t ret = simulate(N, Q, s, t, d, mid);
    
    if (ret == -1) {
      left = mid;
    } else {
      right = mid;
    }
  }
  
  if (left == 0 && simulate(N, Q, s, t, d, 0) >= 0) {
    return -1;
  }
  
  if (simulate(N, Q, s, t, d, right) == -1) {
    return right;
  } else {
    return left;
  }
}

int64_t search_right(uint64_t N, uint64_t Q, const std::string &s, const std::string &t, const std::string &d)
{
  int64_t left = 0, right = N;
  
  while (right - left > 1) {
    int64_t mid = (left + right) >> 1;
    int64_t ret = simulate(N, Q, s, t, d, mid);
    
    if (ret == N) {
      right = mid;
    } else {
      left = mid;
    }
  }
  
  if (right == N && simulate(N, Q, s, t, d, N - 1) < N) {
    return N;
  }
  
  if (simulate(N, Q, s, t, d, left) == N) {
    return left;
  } else {
    return right;
  }
}

int main()
{
  uint64_t N, Q;
  std::cin >> N >> Q;

  std::string s;
  std::cin >> s;
  
  std::string t(Q, ' '), d(Q, ' ');
  for (uint64_t q = 0; q < Q; ++q) {
    std::cin >> t[q] >> d[q];
  }
  
  int64_t left = search_left(N, Q, s, t, d);
  
  int64_t right = search_right(N, Q, s, t, d);
  
  std::cout << (right - left - 1) << std::endl;
  
  return 0;
}