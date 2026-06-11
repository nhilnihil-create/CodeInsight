#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,T,A;
    cin >>N>>T>>A;
    vector<double>vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    vector<double>vec2(N);
    for(int i=0;i<N;i++){
        double a=(T-vec.at(i)*0.006);
      vec2.at(i)=abs(a-A);
    }
 double b=9999;
 int c;
    for(int i=0;i<N;i++){
      if(vec2.at(i)<b){
          b=vec2.at(i);
          c=i+1;
      }
    }
    cout << c<<endl;
}