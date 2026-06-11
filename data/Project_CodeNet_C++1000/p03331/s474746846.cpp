#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include<set> 
#include<math.h>
#define pai arccos(-1);
#define keta(n) cout << fixed << setprecision((n));
#define ll long long;

int func(int x){
  int sum = 0;
  while(x>0){
    sum += x%10;
    x /= 10;
  }
  return sum;
}

int main(){
  int n;
  cin>>n;
  int d = n;
  for(int i=1;i<n;i++){
    int a= func(i);
    int b= func(n-i);
    d = min(d,a+b);
  }
  
  cout<<d;
        


}
