#include<iostream>
//#include<string>


using namespace std;

int main(){
  int N,sum=99999;
  cin >>N;
  int a;
 for(int i =0;i<N;i++){
   cin>>a;
   int j=0;
 while(a%2==0){
   a/=2;
   j++;
 }
 if(j<sum)sum =j;
  
 }cout <<sum<<endl;
}
  