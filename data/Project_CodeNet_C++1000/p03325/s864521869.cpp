#include<bits/stdc++.h>
using namespace std;


int get_answer(int num){
  int cnt = 0;


  while(!(num&1)){
    num = num/2;
    cnt++;
  }

  return cnt;
}


int main(){


int n;
cin>>n;
int a[n];

long long sum = 0;
for(int i=0;i<n;i++){
  cin>>a[i];

  sum += get_answer(a[i]);
}

cout<<sum<<"\n";

  return 0;
}