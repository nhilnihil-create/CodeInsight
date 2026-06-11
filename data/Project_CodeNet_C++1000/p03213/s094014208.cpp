#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

vector<int> primes={2,3,5,7,11,
                    13,17,19,23,29,
                    31,37,41,43,47,
                    53,59,61,67,71,
                    73,79,83,89,91,
                    97};

int main(){
  int n;
  cin>>n;
  vector<int> sisu(26);
  rep(i,26){
    int p=0;
    int q=primes[i];
    while(q<=n){
      p+=n/q;
      q*=primes[i];
    }
    sisu[i]=p;
  }
  int ans=0;
  if(sisu[0]>=74) ans++;
  int ijo2=0,ijo4=0,ijo14=0,ijo24=0;
  rep(i,26){
    if(sisu[i]>=2) ijo2++;
    if(sisu[i]>=4) ijo4++;
    if(sisu[i]>=14) ijo14++;
    if(sisu[i]>=24) ijo24++;
  }
  ans+=(ijo2-1)*ijo24+(ijo4-1)*ijo14+(ijo2-2)*ijo4*(ijo4-1)/2;
  cout<<ans<<endl;
}