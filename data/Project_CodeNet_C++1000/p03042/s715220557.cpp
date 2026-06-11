#include <bits/stdc++.h>
using namespace std;


int main ()
{
   int N;
   cin >>N;
   int t;
   t=N%100;
   N=N/100;
   if(N <= 12 && t <= 12 && t>0 &&N>0){
      cout <<"AMBIGUOUS"<<endl;
   }else if(t<=12 && t>0){
      cout<< "YYMM"<<endl;
   }else if(N<=12 && N>0){
      cout<<"MMYY"<<endl;
   }else{
      cout <<"NA"<<endl;
   }
}