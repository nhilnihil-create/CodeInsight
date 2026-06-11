#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,i,j;
  cin >> a >> b;
  a--;
  b--;
  cout << "42 100" << endl;
  for(j=0;j<100;j++)
    cout << ".";
  cout << endl;
  for(i=0;i<10;i++){
    for(j=0;j<50;j++){
      cout << ".";
      if(b>0){
        cout << "#";
        b--;
      }else{
        cout << ".";
      }
    }
    cout << endl;
    for(j=0;j<100;j++)
      cout << ".";
    cout << endl;
  }
  for(j=0;j<100;j++)
    cout << "#";
  cout << endl;
  for(i=0;i<10;i++){
    for(j=0;j<50;j++){
      cout << "#";
      if(a>0){
        cout << ".";
        a--;
      }else{
        cout << "#";
      }
    }
    cout << endl;
    for(j=0;j<100;j++)
      cout << "#";
    cout << endl;
  }
  return 0;
}