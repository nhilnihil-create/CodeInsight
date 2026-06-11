#include<iostream>
#include<algorithm>
int main(void){
  int N;
  std::cin >> N;
  int mochi[N];
  for (int i=0;i<N;i++){
    std::cin >> mochi[i];
  }
  std::sort(mochi, mochi+N);
  std::reverse(mochi, mochi+N);

  int count = 1;
  for (int i=0;i<N-1;i++){
    if (mochi[i] > mochi[i+1]) count++;
  }
  std::cout << count << std::endl;

  return 0;
}