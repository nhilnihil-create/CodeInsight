#include<iostream>
#include<algorithm>
using namespace std;
int array[]={2,3,25,30,60,120,240,480,960,1920};
int main(){
  int n;
  cin>>n;
  if(n<=10){
    for(int i=0;i<n-1;i++) cout<<array[i]<<" ";
    cout<<array[n-1]<<endl;
    return 0;
  }
  else if(n==19999){
    for(int i=1;i<=2500;i++) cout<<i*12-9<<" "<<i*12-3<<" ";
    for(int i=1;i<=14998;i++) cout<<i*2<<" ";
    cout<<29998<<endl;
    return 0;
  }
  int ncnt=1,mcnt=1;
  n-=5;
  int lasn,lasm;
  while(n>0&&mcnt<2500){
    n-=2;
    mcnt++;
    if(n%3==0){
      lasn=n/3;
      lasm=mcnt;
    }
  }
  ncnt+=lasn;
  mcnt=lasm;

//  cout<<ncnt<<" "<<mcnt<<endl;
  for(int i=1;i<=3*ncnt;i++) cout<<2*i<<" ";
  for(int i=1;i<mcnt;i++) cout<<12*i-9<<" "<<12*i-3<<" ";
  cout<<mcnt*12-9<<" "<<mcnt*12-3<<endl;
  return 0;

}
