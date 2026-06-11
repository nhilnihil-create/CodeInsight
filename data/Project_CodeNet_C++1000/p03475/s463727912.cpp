#include <iostream>
#include <vector>
#include <cmath>

/**
 * find out minimum s + nf s.t. t < s + nf
 */
int get_ceil(int t, int s, int f)
{
  if(t < s) return s;

  int n = std::ceil((t - s) / float(f));
  return s + n * f;
}

/**
 * get minimum arrival time from i -> N
 */
int get_min_arrival_time(
    int i, int N,
    const std::vector<int> &C,
    const std::vector<int> &S,
    const std::vector<int> &F)
{
  int t = 0;
  //std::cout << "i=" << i << " N=" << N << std::endl;
  for(int j=i; j<N-1; j++) {
    //std::cout << "j=" << j << " t=" << t << std::endl;
    t = get_ceil(t, S[j], F[j]);
    //std::cout << "train at " << t << std::endl;
    t += C[j];
    //std::cout << "arrive at " << t << std::endl;
  }
  return t;
}


int main()
{
  int N;
  std::cin >> N;
  std::vector<int> C(N-1);
  std::vector<int> S(N-1);
  std::vector<int> F(N-1);

  for(int i=0; i<N-1; i++) {
    std::cin >> C[i] >> S[i] >> F[i];
  }

  for(int i=0; i<N; i++) {
    std::cout << get_min_arrival_time(i, N, C, S, F) << std::endl;
  }

  return 0;
}
