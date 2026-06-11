#include <bits/stdc++.h>
using namespace std;
int main() {
 int N,T,A;
 cin>>N>>T>>A;
 double min=10000000;
 int answer=0;
 vector<int>data(N);
 for(int i=0; i<N; i++){
    cin>>data.at(i);
    int g=data.at(i);
    double h=(abs(A-(T-0.006*g)));
    if(min>h){
        min=h;
        answer=i+1;
    }
 }
 cout<<answer<<endl;

 }