#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(6);
  for(int i = 0;i < 6;i++){
    cin >> a[i];
  }
  for(int i = 0;i < 5;i++){
    for(int j = 0;j < 5;j++){
      if(i == j)continue;
      if(abs(a[i] - a[j]) > a[5]){
        cout << ":(" << endl;
        return 0;
      }
  	}
  }
  cout << "Yay!" << endl;
}