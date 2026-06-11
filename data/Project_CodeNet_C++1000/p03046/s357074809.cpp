#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long m,k;
  cin >> m>>k;
  if(k==0){
    rep(i,1<<(m+1)){
      cout<<i/2<<" ";
    }
  }
  else{
    if(m==1||k>=(1<<m)){
      cout<<-1<<endl;
    }
    else{
      long n=1<<(m+1);
      vector<long>a(n);
      a[0]=k;
      a[n/2]=k;
      rep2(i,1,n/2){
        if(i<k){
          a[i]=i%(n/2);
        }
        else{
          a[i]=(i+1)%(n/2);
        }
      }
      rep2(i,1,n/2){
        a[n/2+i]=a[n/2-i];
      }
      rep(i,n){
        cout<<a[i]<<" ";
      }
    }
  }
}