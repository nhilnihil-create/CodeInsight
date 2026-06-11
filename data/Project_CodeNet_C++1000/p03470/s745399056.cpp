#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0, count=0;
  vector<int> d(101);
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> d.at(i);
  }
  sort(d.rbegin(),d.rend());
  for(int i=0;i<N;i++){
    if(d.at(i) > 0){
      count++;
      for(int j=i+1;j<N;j++){
        if(d.at(i) == d.at(j)){
          d.at(j)=-1;
        }
      }//for j
    }
  }
  cout << count << endl;
}