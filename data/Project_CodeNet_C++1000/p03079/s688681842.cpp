#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> L;
  int l;
  for(int i=0;i<3;i++){
    cin >> l;
    L.push_back(l);
  }
  sort(L.begin(),L.end());
  if(L[0]==L[2]){
    cout<< "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  

}