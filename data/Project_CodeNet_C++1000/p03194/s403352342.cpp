#include<bits/stdc++.h>
using namespace std;
long long N,P;
//priority_queue<long long> Q;
long long ans=1;

long long pow1(long long a,long long b){
  long long ans=1;
  if(b==0){
    return 1;
  }
  else{
    for(long long i=0;i<b;i++){
      ans = a*ans;
      //ans%=1000000007;//これでいい
    }
    return ans;
  }
}
int main(){
  cin >> N >> P;
  long long i=2;
  long long cnt=0;
  if(N==1) cout << P << endl;
  else{
    while(P>1){
      if(i>sqrt(P)+1) break;
      while(P%i==0){
        P=P/i;
        //num[i]++;
        cnt++;

        //cout << P << endl;
      }

      if(cnt>=N){
        ans*=pow1(i,cnt/N);
        //ans*=i;
        //Q.push(i);
        //cout << i << endl;
        //return 0;
      }
      i++;
      cnt=0;
    }

    cout << ans << endl;
  }
  return 0;
}
