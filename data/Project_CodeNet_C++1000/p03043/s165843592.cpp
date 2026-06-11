#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,dn,nm=0;
  cin >>n>>k;
  rep(i,n){
    int cs=i+1;
    //cout << cs<<' '<<k<<endl;
    while(cs<k){
      cs*=2;
      //cout <<cs<<endl;
    }
    if(i==0)dn=cs;
    nm+=dn/(cs/(i+1));
    //cout << nm;
  }
  cout << fixed << setprecision(13) <<(double)nm/(dn*n);
}