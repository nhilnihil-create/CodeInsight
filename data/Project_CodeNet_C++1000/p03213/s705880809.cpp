#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX =510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2; i<MAX; i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}

ll COM(int n, int k){
  if(n<k)
    return 0;
  if(n<0 || k<0)
    return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
  COMinit();
  //約数が75個=3*5*5,15*5,25*3,75をそれぞれ。
  //2,4,14,24,74乗の数をカウントする？
  int N;
  cin>>N;
  vector<int> X2(101,0),X4(101,0),X14(101,0),X24(101,0),X74(101,0);
  unordered_map<int,int> mp;
  for(int i=2; i<=100; i++){
    int k=i;
    for(int j=2; j*j<=k; j++){
      if(k%j==0){
        int tmp=mp[j];
        k/=j;
        mp[j]=tmp+1;
        if(tmp+1==2)
          X2[i]++;
        else if(tmp+1==4)
          X4[i]++;
        else if(tmp+1==14)
          X14[i]++;
        else if(tmp+1==24)
          X24[i]++;
        else if(tmp+1==74)
          X74[i]++;
        j--;
      }
    }
    if(k>1){
      int tmp=mp[k];
      mp[k]=tmp+1;
      if(tmp+1==2)
        X2[i]++;
      else if(tmp+1==4)
        X4[i]++;
      else if(tmp+1==14)
        X14[i]++;
      else if(tmp+1==24)
        X24[i]++;
      else if(tmp+1==74)
        X74[i]++;
    }
  }
  for(int i=2; i<=100; i++){
    X2[i]=X2[i-1]+X2[i];
    X4[i]=X4[i-1]+X4[i];
    X14[i]=X14[i-1]+X14[i];
    X24[i]=X24[i-1]+X24[i];
    X74[i]=X74[i-1]+X74[i];
  }
  ll ans=0;
  ans+=COM(X2[N]-2,1)*COM(X4[N],2);
  ans+=COM(X14[N],1)*COM((X4[N]-1),1);
  ans+=COM(X24[N],1)*COM((X2[N]-1),1);
  ans+=COM(X74[N],1);
  cout<<ans<<endl;
}
