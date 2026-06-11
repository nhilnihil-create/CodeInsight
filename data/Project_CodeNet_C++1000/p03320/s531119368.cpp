#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
  int K;cin>>K;
  vll ans={1,2,3,4,5,6,7,8,9,
  19,29,39,49,59,69,79,89,99,
199,299,399,499,599,699,799,899,999};

  //digit は、「その」桁数から3を引いたもの。
  for (int digit=0;digit<12;++digit){
    ll base=0;
    for (int i=0;i<=digit;++i){
      base+=9*(ll)pow(10,i);
    }
    for(int k=100;k<=999;++k){
      ll upper=k*(ll)pow(10,digit+1);
      int a=k/100;
      int b=(k-a*100)/10;
      int c=(k-a*100-b*10);
      ll num=upper+base;

      if(a>=digit+2){
        if(b==9&&c==9){
          ans.push_back(num);
        }
      }

      else{
        if ((11*a+b>=digit+1)&&(c==9)){
          ans.push_back(num);
        }
        else if (11*a+b<digit+1){
          ans.push_back(num);
        }
      }
    }
  }

  for (int k=0;k<K;++k){
    cout << ans[k] << endl;
  }

  return 0;
}