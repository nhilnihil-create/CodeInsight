#include <iostream>

using namespace std;

int main() {
  bool exist = false;
  bool unexist = true;
  int N, Y, thou,five,ten;
  cin >> N>> Y;
  for(int a=0;a<=N;++a){
    for(int b=0;a+b<=N;++b){
      int c = N-a-b;
      int sum = 1000*a+5000*b+10000*c;
      if(Y==sum){
        exist = true;
        unexist = false;
        thou = a;
        five = b;
        ten = c;
      }
    }
  }
  if(exist){
    cout<<ten<<" "<<five<<" "<<thou<<endl;
  }
  if(unexist){
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }
}