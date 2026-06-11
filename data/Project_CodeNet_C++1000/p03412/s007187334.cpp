#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<numeric>

using namespace std;

long long MOD = 1000000007;

int n;

long long a[200005];
long long as[2][200005];

long long b[200005];
long long bs[2][200005];

long long solve(int k, long long base){

  int now = k % 2;
  int prev = now ^ 1;

  int cnta = 0;
  int cntb = 0;

  for(int i = 0;i<n;i++)if((as[prev][i] & base) == 0) cnta++;
  for(int i = 0;i<n;i++)if((bs[prev][i] & base) == 0) cntb++;

  int cnta0 = 0;
  int cnta1 = 0;

  int cntb0 = 0;
  int cntb1 = 0;

  for(int i = 0;i<n;i++){
    if(as[prev][i] & base) as[now][cnta + (cnta1++)] = as[prev][i];
    else as[now][cnta0++] = as[prev][i];

    if(bs[prev][i] & base) bs[now][cntb + (cntb1++)] = bs[prev][i];
    else bs[now][cntb0++] = bs[prev][i];
  }

  //cout<<k<<" "<<base<<endl;
  //cout<<cnta<<" "<<cnta0<<" "<<cnta1<<endl;
  //cout<<cntb<<" "<<cntb0<<" "<<cntb1<<endl;
  //for(int i=0;i<n;i++)cout<<as[now][i]<<" ";cout<<endl;
  //for(int i=0;i<n;i++)cout<<bs[now][i]<<" ";cout<<endl;

  long long cnt = 0;
  long long ma = n-1;
  long long mi = n-1;
  long long mma = n-1;

  for(int i=0;i<n;i++){
      while( (mma!=-1) && ((as[now][i]%(base*2LL)) + (bs[now][mma]%(base*2LL)) >= base*3LL) ) mma--;
      while( (ma!= -1) && ((as[now][i]%(base*2LL)) + (bs[now][ma ]%(base*2LL)) >= base*2LL) ) ma--;
      while( (mi!= -1) && ((as[now][i]%(base*2LL)) + (bs[now][mi ]%(base*2LL)) >= base    ) ) mi--;
      //cout<<i<<" "<<ma<<" "<<mi<<" "<<mma<<endl;
      cnt += (ma-mi) + ((long long)(n-1)-mma);
  }

  return cnt%2LL;

}

int main(){
  cin>>n;

  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++){
    as[1][i] = a[i];
    bs[1][i] = b[i];
  }

  long long ans = 0;
  long long base = 1;

  for(int i=0;i<=30;i++){
    ans += base * solve(i,base);
    base *= 2LL;
    //cout<<ans<<endl;
  }

  cout<<ans<<endl;

  return 0;
}
