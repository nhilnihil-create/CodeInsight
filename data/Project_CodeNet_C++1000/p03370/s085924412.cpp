#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int N,X;
  int m[1000];
  int min=99999;
  int sum=0;
  int count=0;

  cin >> N >> X;
  for (int i=0;i<N;i++){
    cin >> m[i];
  }
  for (int i=0;i<N;i++){
    if(min > m[i]){
      min = m[i];
    }
    sum+=m[i];
    count++;
  }
  while(true){
    if(sum + min > X ){
      break;
    }
    sum+=min;
    count++;
  }
  
  cout << count << endl;
  
  return 0;
}