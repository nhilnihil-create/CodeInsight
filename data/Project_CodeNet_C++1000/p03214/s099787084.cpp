#include <bits/stdc++.h>
using namespace std;

#define double long double
     
int main() {
  int N;
  cin >> N;
      
  vector<int>vec(N);
  int count = 0;
      
  for(int i=0;i<N;i++){
    cin >> vec.at(i);
    count+=vec.at(i);
  }        
        
  double ave;
  ave = (double)count/N;
  int number =0;
      
  for(int i=0;i<N-1;i++){
    double a= min(abs((double)vec.at(number)-ave),abs((double)vec.at(i+1)-ave));
    if(a != abs((double)vec.at(number)-ave)){
      number = i+1;
    }
  }
  cout << number <<endl;
      
}
