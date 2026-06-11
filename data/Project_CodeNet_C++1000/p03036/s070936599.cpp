#include <iostream>
using namespace std;

int main() {
	int r=2;
  int x=20;
  int d=10;
  cin>>r;
  cin>>d;
  cin>>x;
  
  for(int i=0; i<10;i++){
    x=r*x-d;
    cout<< x<<endl;
  }
  
	return 0;
}
