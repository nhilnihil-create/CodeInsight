#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int n;cin>>n;
  int d,x;cin>>d>>x;
  int arr[n];
  for(int i=0;i<n;i++){
      cin >> arr[i];
  }
  

  int ans=0;
  for(int i=0;i<n;i++){
      int day=0;
      int param=0;
      while(true){
          day = param*arr[i]+1;

          //printf("day: %d\n",day);
          if(day<=d){
              ans ++;
              param ++;
          }else{
              break;
          }
          
      }
  }

    cout << ans + x << endl;
}