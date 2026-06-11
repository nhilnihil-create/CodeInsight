#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int n,k,i,j;
  cin >> n >> k;
  double ans=0;
  for(i=1;i<=n;i++){
    double ans1=1;
    j=i;
    while(j<k){
      ans1*=1/(double)2;
      j=j*2;
    }
    ans+=1/(double)n*ans1;
  }
  printf("%.12lf\n",ans);
}