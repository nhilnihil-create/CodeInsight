#include<bits/stdc++.h>
using namespace std;

int main(){
  int n , k;
  cin >> n >> k;
  //kが奇数
  if(k&1){
    int64_t count = n/k;
    cout << count*count*count;
  }else{
    //kが偶数
    k/=2;
    int64_t count = n/k;
    int64_t even = count/2;
    int64_t odd = (count+1)/2;
    
    cout << even*even*even+odd*odd*odd;
    
  }
}