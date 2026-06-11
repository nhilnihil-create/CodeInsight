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
  if(n%func(n)==0)cout<<"Yes";
  else cout<<"No";
  
        


}
