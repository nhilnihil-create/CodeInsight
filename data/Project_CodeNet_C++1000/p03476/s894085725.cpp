#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
bool sosuu(int n){
  int d=pow(n,0.5)+1;
  if(n==2)return true;
  int i=2;
  while(i<=d){
    if(n%i!=0){i++;}
    else return false;
  }
  return true;
}
signed main() {
int q;
cin>>q;
int ans;
int l,r;
int s[100001];
s[1]=0;s[0]=0;
for(int i=3;i<=100001;i+=2){if(sosuu(i)&&sosuu((i+1)/2))s[i]=s[i-2]+1;else s[i]=s[i-2];}


for(int i=0;i<q;i++){
  cin>>l>>r;
  ans=0;
  if(l>=2)ans=s[r]-s[l-2];
  else ans=s[r];
  cout<<ans<<endl;
}

}
