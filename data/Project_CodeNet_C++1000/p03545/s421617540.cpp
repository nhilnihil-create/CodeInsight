#include<iostream>
#include<string>
using namespace std;
using ll=long long;
int main(){

  string S;
  cin>>S;
  int A=S[0]-'0';
  int B=S[1]-'0';
  int C=S[2]-'0';
  int D=S[3]-'0';
  if(A+B+C+D==7){
  
    cout<<S[0]<<"+"<<S[1]<<"+"<<S[2]<<"+"<<S[3]<<"=7";
    return 0;
  }
  if(A+B+C-D==7){
  
    cout<<S[0]<<"+"<<S[1]<<"+"<<S[2]<<"-"<<S[3]<<"=7";
    return 0;
  }
  if(A+B-C+D==7){
        
    cout<<S[0]<<"+"<<S[1]<<"-"<<S[2]<<"+"<<S[3]<<"=7";
    return 0;
  }  
  if(A+B-C-D==7){
  
    cout<<S[0]<<"+"<<S[1]<<"-"<<S[2]<<"-"<<S[3]<<"=7";
    return 0;
  }
  if(A-B+C+D==7){

    cout<<S[0]<<"-"<<S[1]<<"+"<<S[2]<<"+"<<S[3]<<"=7";
    return 0;    
  }
  if(A-B+C-D==7){
  
    cout<<S[0]<<"-"<<S[1]<<"+"<<S[2]<<"-"<<S[3]<<"=7";
    return 0;  
  }
  if(A-B-C+D==7){
  
    cout<<S[0]<<"-"<<S[1]<<"-"<<S[2]<<"+"<<S[3]<<"=7";
    return 0;  
  }
  if(A-B-C-D==7){
  
    cout<<S[0]<<"-"<<S[1]<<"-"<<S[2]<<"-"<<S[3]<<"=7";
    return 0;    
  }
  return 0;
}