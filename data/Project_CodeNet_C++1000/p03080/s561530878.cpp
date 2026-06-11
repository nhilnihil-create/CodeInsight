#include <iostream>

using namespace std;

int main(){
  int N;
  std::string s;
  cin >> N >> s;
  int r_num=0;
  for(int i = 0;i<N; i++){
    if(s[i] == 'R'){
      r_num++;
    }
  }
  if(r_num > N-r_num){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }

  return 0;
}
