#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a;
  cin >> a;
  if(a == 25){
    cout << "Christmas\n";
  }
  else if(a == 24){
    cout << "Christmas" << " " << "Eve" << "\n";
  }
  else if(a == 23){
    cout << "Christmas" << " " << "Eve"<< " " << "Eve"  << "\n";
  }
  else if(a == 22){
    cout << "Christmas" << " " << "Eve"<< " " << "Eve" << " " << "Eve" << "\n";
  }
}
  
  