#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> vec(N);

  for (int i=0; i<N; i++){

    cin>>vec.at(i);
  }
  int M;
  cin>>M;
  vector<string> vec2(M);

  for(int i =0; i<M; i++){
  cin>>vec2.at(i);
  }

  int x=0;

  for(int i=0; i<N; i++){
      int y=0;
      for(int j=0; j<N;j++){
          
      if(vec.at(i)==vec.at(j))
      y++;
      }
      for (int k=0; k<M; k++){
          if (vec.at(i)==vec2.at(k))
          y--;
      }
      if(x<y)
      x=y;
  }
  cout<<x<<endl;
  
}