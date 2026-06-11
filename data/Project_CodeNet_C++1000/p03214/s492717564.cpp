#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;

  vector<float> vec(N);

  for(int i=0;i<N;i++){
    cin >> vec.at(i);
  }

  float ave;

  for(int i=0;i<N;i++){
    ave+=vec.at(i)/N;
  }
  //cout << ave << endl;

  vector<float> sa(N);

 for(int i=0;i<N;i++){
    sa.at(i)=max(ave-vec.at(i), vec.at(i)-ave);
  } 

  sort(sa.begin(), sa.end());

 /*for(int i=0;i<N;i++){
    cout << sa.at(i) << endl;
  }*/

  for(int i=0;i<N;i++){
    if(sa.at(0)==max(ave-vec.at(i), vec.at(i)-ave)){
      cout << i << endl;
      break;
    }
  }

  

}