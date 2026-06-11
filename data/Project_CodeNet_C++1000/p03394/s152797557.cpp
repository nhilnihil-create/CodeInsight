#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n==3) cout << "2 5 63" << endl;
  else if(n==4) cout << "2 5 20 63" << endl;
  else{
    int a[20000];
    for(int i=0;i<5000;i++){
      a[i]=6*i+2;
      a[i+5000]=6*i+3;
      a[i+10000]=6*i+4;
      a[i+15000]=6*(i+1);
    }
    sort(a,a+20000);
    int x=(n-1)/8,y=(n-1)%8+1;
    for(int i=0;i<x;i++){
      for(int j=0;j<8;j++){
        cout << a[8*i+j] << " ";
      }
    }
    if(y%2==0) cout << a[8*x+7] << " ";
    if(y>=3) cout << a[8*x+1] << " " << a[8*x+5] << " ";
    if(y>=5) cout << a[8*x] << " " << a[8*x+2] << " ";
    if(y>=7) cout << a[8*x+4] << " " << a[8*x+6] << " ";
    cout << a[8*x+3] << endl;
  }
}