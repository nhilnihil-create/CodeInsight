#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int count = 0;
  for(int i = 0; i < N; i++){
    int a;
    int tmp_count = 0;
    cin >> a;
    while(true){
    	if(a % 2 == 0){
          tmp_count++;
          a /= 2;
        }else{
          break;
        }
    }
    if(i == 0 || tmp_count <= count){
      count = tmp_count; 
    }
  }
  cout << count << endl;
}