#include<iostream>
#include<string>
#include<vector>
using namespace std;
 int main(){
   int n;
   double sum=0;
   cin >> n;
   vector<double>x(n);
   vector<string>u(n);
   for(int i=0; i<n; i++){
     cin >> x.at(i) >> u.at(i);
     if(u.at(i)=="JPY"){
       sum+=x.at(i);
     }
     else{
       sum+=x.at(i)*380000.0;
     }
   }
   cout << sum << endl;

 }
