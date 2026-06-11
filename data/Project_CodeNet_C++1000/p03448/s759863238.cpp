#include<iostream>

using namespace std;

int main() {
  int A,B,C,N;
  cin >> A >> B >> C >> N;
  
  int res=0;
  
  for(int a=0; a<=A; a++) {
    for(int b=0; b<=B; b++) {
      for(int c=0; c<=C; c++) {
        int answer = 500*a + 100*b + 50*c;
        if( answer == N ) res++;
      }
    }
  }
  
  cout << res << endl;
}
    