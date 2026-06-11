#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> tower(5);
  for (int i = 0;i< tower.size();i++){
  	cin >> tower.at(i);
  }
  int key,flag = 0;
  cin >> key;
  for(int i = 0;i < tower.size()-1;i++){
    for(int j = i+1;j < tower.size();j++){
      if(tower.at(j)-tower.at(i) > key){
        cout << ":(" << endl;
        flag = 1;
        break;
      }
    }
    if(flag == 1)
      break;
  }
  if(flag == 0)
    cout << "Yay!" << endl;
}
