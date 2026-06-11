#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; long long int a,b; cin >> n >> a >> b;
  if(n > a*b || n < a + b -1){cout << "-1" << endl; return 0;}
  long long int d = a*b - n;
  vector<int> v;
  for(int i=0;i < b ;i++){
  	if(i==0){
      for(int i=a-1;i>=0;i--) printf("%d ", n-i);
      n -= a;
    }else{
      if(d >= a-1){
       for(int i=0;i>=0;i--) printf("%d ", n-i);
       n -= 1;
       d -= a-1;
      }else if(d == 0){
        for(int i=a-1;i>=0;i--) printf("%d ", n-i);
      	n -= a;
      }else{
      	int r = d % (a-1);
        for(int i=a-1-r;i>=0;i--) printf("%d ", n-i);
      	d -= r;
        n -= a-r;
      }
    }
  }
  printf("\n");
}
