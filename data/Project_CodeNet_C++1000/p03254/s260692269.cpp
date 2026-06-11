#include<bits/stdc++.h>
using namespace std;


int main(){

  int N,x,tmp,num;
  vector<int> a;
  
  cin >> N >> x;
  for(int i=0;i<N;i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(),a.end());

  num=0;
  for(int i=0;i<N;i++){
    if((x<a.at(i)) || ( i==N-1  && x > a.at(i) )){
      break;
    }else{
      num++;
      x -= a.at(i);
    }
  }

  cout << num << endl;

}
