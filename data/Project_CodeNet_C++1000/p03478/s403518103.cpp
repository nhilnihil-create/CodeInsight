#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N,A,B;
  cin>>N>>A>>B;
  int sum=0;
  for(int i=1;i<=N;i++){
    int n=i;
    int cnt=0;
    while(n!=0){
      cnt+=n%10;
      n/=10;
    }
    if(A<=cnt&&cnt<=B){
      sum+=i;
    }
  }
  cout<<sum<<endl;
}