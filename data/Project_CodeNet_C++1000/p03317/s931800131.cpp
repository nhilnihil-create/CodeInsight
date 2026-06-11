#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define ll long long
#define test(a) cout << "*" << a << endl;
int main(){
  int i,j;
  int numLong,numChoice;
  int a[100000];
  int aMin,aTmp;
  int count = 0;
  
  cin >> numLong >> numChoice; 
  
  rep0(i,numLong){ 
    cin >> a[i];
    if(i==0){
      aMin = a[i];
    }
    if(a[i] < aMin){
      aMin = a[i];
    }
  
  }
  
  rep0(i,numLong){
    if(a[i] == aMin){
      count++;  
    }
  }
  
  
  if((numLong-count)%(numChoice-1) != 0)
    cout << (numLong-count)/(numChoice-1) +1 << endl;
  else
    cout << (numLong-count)/(numChoice-1) << endl;

}