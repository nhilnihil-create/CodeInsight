#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int>t(N+1);
  vector<int>x(N+1);
  vector<int>y(N+1);
  vector<int>T(N);
  vector<int>X(N);
  vector<int>Y(N);
  
  t.at(0)=0;
  x.at(0)=0;
  y.at(0)=0;
  
  for(int i=1; i<N+1; i++){
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }
  
   for(int i=0; i<N; i++){
     T.at(i) = abs(t.at(i+1)-t.at(i));
     X.at(i) = x.at(i+1) - x.at(i);
     Y.at(i) = y.at(i+1) - y.at(i);
   }
  
  for(int i=0; i<N; i++){
    if(T.at(i)< abs(X.at(i))+abs(Y.at(i))){
      cout<<"No"<<endl;
      break;
    }
    else if(abs((abs(X.at(i))+abs(Y.at(i))-T.at(i)))%2==1){
         cout<<"No"<<endl;
      break;
       }
    else if(i==N-1){
      cout <<"Yes" <<endl;
    }
            
  }
}