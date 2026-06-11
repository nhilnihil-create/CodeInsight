#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<tuple<int, int, int>> T(N);
  int X, Y, H;
  for(int i=0; i<N; i++){
    cin >> X >> Y >> H;
    T.at(i)=make_tuple(H, X, Y);
  }
  sort(T.begin(), T.end());
  int Ansx, Ansy, Ansh;
  for(int x=0; x<=100; x++){
    for(int y=0; y<=100; y++){
      int h=abs(x-get<1>(T.at(N-1)))+abs(y-get<2>(T.at(N-1)))+get<0>(T.at(N-1));
      int k=1;
      for(int i=0; i<N; i++){
        if(max(h-abs(x-get<1>(T.at(i)))-abs(y-get<2>(T.at(i))), 0)!=get<0>(T.at(i))){
          k=0;
          break;
        }
      }
      if(k==1){
        Ansx=x;
        Ansy=y;
        Ansh=h;
      }
    }
  }
  cout << Ansx << " " << Ansy << " " << Ansh << endl;      
}