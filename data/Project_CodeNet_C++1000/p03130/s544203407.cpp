#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[4];
int main(){
  for(int i = 0; 6 > i; i++){
    int tmp;cin>>tmp;tmp--;
    a[tmp]++;
  }
  vector<int> z;
  for(int i = 0; 4 > i; i++){
    z.push_back(a[i]);
  }
  sort(z.begin(),z.end());
  for(int i = 0; 4 > i; i++){
    if(i < 2){
      if(z[i] != 1){
        cout << "NO" << endl;
        return 0;
      }
    }else{
      if(z[i] != 2){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}