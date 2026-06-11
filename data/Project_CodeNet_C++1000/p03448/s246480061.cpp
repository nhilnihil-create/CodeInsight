#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
int main(){
 int a,b,c,x;
  cin>>a>>b>>c>>x;
  int count=0;
  rep(i,a+1){
    rep(j,b+1){
      if(x-500*i-100*j>=0&&(x-500*i-100*j)/50<=c) count++;
    }
  }
  cout<<count<<endl;
return 0;
}