#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <string>

using namespace std;
long long f(long long a,long long cnt){
  long long ret=1;
  if(cnt==0)return 1;
  if(cnt%2==1){
    long long x = f(a,cnt/2);
    return a*x*x;
  }
  else {
    long long x = f(a,cnt/2);
    return x*x;
  }
}
int main(){
  long long int n,m,i,j,k,p;
  long long ret=1;
  cin >> n >> p;
  for(i=2;i*i<=p;i++){
    long long cnt=0;
    long long x = 1;
    while(p%i==0){
      cnt++;
      p/=i;
    }
    x = f(i,cnt/n);
    if(cnt>=n)ret*=x;
  }
  if(n==1&&p>0)ret*=p;
  /*map<long long,long long>::iterator itr;
  for(itr=mp.begin();itr!=mp.end();itr++){
    if(itr->second<n)continue;
    ret*=(itr->first)*(itr->second/n);
  }*/
  cout << ret << endl;
  return 0;
}
