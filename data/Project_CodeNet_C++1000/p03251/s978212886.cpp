#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int N,M,X,Y;
 cin>>N>>M>>X>>Y;
 vector<int>x(N);
 vector<int>y(M);
 for(int i=0;i<N;i++){
     cin>>x[i];
 }
 x.push_back(X);
 for(int i=0;i<M;i++){
     cin>>y[i];
 }
 y.push_back(Y);

 for(int i=-100;i<=100;i++){
     int miny=*min_element(y.begin(),y.end());
     int maxx=*max_element(x.begin(),x.end());
    if(miny>=i&&maxx<i){
        cout<<"No War"<<endl;return 0;
    }
 }
 
 cout<<"War"<<endl;
 return 0;}