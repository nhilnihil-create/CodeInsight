#include <bits/stdc++.h>
using namespace std;
 int main(){
   int N,T,A;
   cin >>N>>T>>A;
	vector<double> vec(N);
	int c=0;
   for(int i=0;i<N;i++){
	int H;
     cin>>H;
     double S,s;
     s=A-(T-(H*0.006));
     if(s<0){
       S=-s;
     }
     else S=s;
     vec.at(i)=S;
     if(i>0){
       if(S<vec.at(c)){
         c=i;
       }
     }
   }
   cout<<c+1<<endl;
 }
