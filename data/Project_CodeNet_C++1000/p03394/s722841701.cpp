#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  if(n>=15000){
    int count=0;
    for(int i=0;i<=30000;i+=2){
      if(i%3!=0){
        cout<<i<<" ";
        count++;
      }
    }
    for(int i=1;i<=30000;i+=2){
      if(i%6==3){
        cout<<i<<" ";
        count++;
      }
    }
    for(int i=6;i<=30000;i+=2){
      if(count==n){
        break;
      }
      if(i%6==0){
        cout<<i<<" ";
        count++;
      }
    }
    return 0;
  }
  if(n>=6){
    cout<<"2 3 4 6 9 12 ";
    int count=6;
    if((n-6)%2==1){
      cout<<"30000 ";
      count++;
    }
    for(int i=13;i<=30000;i++){
      if(count==n){
        return 0;
      }
      if(i%6==2){
        cout<<i<<" "<<i+2<<" ";
        count+=2;
      }
    }
    for(int i=15;i<=30000;i++){
      if(count==n){
        return 0;
      }
      if(i%6==3){
        cout<<i<<" ";
        count++;
      }
    }
    for(int i=18;i<30000;i++){
      if(count==n){
        return 0;
      }
      if(i%6==0){
        cout<<i<<" ";
        count++;
      }
    }
    return 0;
  }
  if(n==5){
    cout<<"2 5 20 63 12600"<<endl;
  }
  if(n==4){
    cout<<"2 5 20 63"<<endl;
  }
  if(n==3){
    cout<<"2 5 63"<<endl;
  }
}