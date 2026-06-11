#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  vector<int> vec(3);
  for(int i=0;i<3;i++){
    cin >> vec[i];
  }
  cin >> N;
  
  int  cnt=0;
  for(int i=0;i<=vec[0];i++){
    for(int j=0;j<=vec[1];j++){
      for(int k=0;k<=vec[2];k++){
        if(N-500*i-100*j-50*k==0){
          cnt++;
        }
      }
    }
  }
  cout << cnt <<endl;
}

    