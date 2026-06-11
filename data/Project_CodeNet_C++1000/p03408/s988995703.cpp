#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N,M;
  cin >> N;
  vector<string> s(N);
  for (int i=0;i<N;i++){
    cin >> s.at(i);
  }
  cin >> M;
  vector<string> t(M);
  for (int i=0;i<M;i++){
    cin >> t.at(i);
  }
  int count = 0;
  for(int i=0;i<N;i++){
    int tempCount = 0;
    string temp = s.at(i);
    for(int j=0;j<N;j++){
      if(s.at(j) == temp) tempCount++;
    }
    for(int j=0;j<M;j++){
      if(t.at(j) == temp) tempCount--;
    }
    if(count < tempCount) count = tempCount;
  }
  if (count > 0){
    cout << count;
  }else{
    cout << 0;
  }
}