#include <iostream>
using namespace std;

int main(){
  int a=0, b=0, c=0;
  string d;
  cin >> d;
  for(int i = 0;i<3;i++){
    if(d.at(i)=='a')a++;
    else if(d.at(i)=='b')b++;
    else c++;
  }
  if(a==1&&b==1&&c==1)cout << "Yes";
  else cout << "No";
}
