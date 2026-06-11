#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long long s(long long left,long long right,vector<long long> &k,long long key){
  long long mid=(left+right)/2;
  if(mid==left)return left;
  if(k[mid]<=key)return s(mid,right,k,key);
  else return s(left,mid,k,key);
}
int main(){
  int a,b,q;
  cin >> a >> b >> q;
  vector<long long> c(a+2);
  vector<long long> d(b+2);
  c[a+1]=2000000000000000;
  d[b+1]=c[a+1];
  c[0]=-100000000000000;
  d[0]=c[0];
  rep(i,a){
    cin >> c[i+1];
  }
  rep(i,b)cin >> d[i+1];
  rep(i,q){
    long long z;
    cin >> z;
    int y=s(0,a+1,c,z);
    int p=y+1;
    int m=s(0,b+1,d,z);
    int w=m+1;
    //cout << y << " " << m  << " " << c[y] << " " << c[p] << " " << d[m] << " " << d[w] << endl;
    long long ans=max(c[p]-z,d[w]-z);
    ans=min(ans,max(z-c[y],z-d[m]));
    //cout << ans << endl;
    ans=min(ans,2*c[p]-z-d[m]);
    ans=min(ans,2*d[w]-z-c[y]);
    //cout << ans << endl;
    ans=min(ans,z+d[w]-2*c[y]);
    ans=min(ans,z+c[p]-2*d[m]);
    cout << ans << endl;
  }
  
}
