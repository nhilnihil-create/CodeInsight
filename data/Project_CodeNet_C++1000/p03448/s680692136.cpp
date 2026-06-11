#include <iostream>
#include <vector>
using namespace std;

int main(){
  int A,B,C,x;
  int k = 0;//何通りあるのかをカウントする変数
  int l = 0;
  cin>>A>>B>>C>>x;
  for(int a = 0;a <= A;a++){
    for(int b = 0;b <= B;b++){
      for(int c = 0;c <= C;c++){
        l = 500 * a + 100 * b + 50 * c;
        if(l == x){
          k++;
        }
      }
    }
  }
  cout<<k<<endl;
}