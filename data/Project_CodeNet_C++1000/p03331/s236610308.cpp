#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int x[110];
int y[110];

int func(int y){
  int sum=0;
  int x=y;
  while(x!=0){
    sum+=x%10;
    x/=10;
  }
  return sum;
}
int main() {
 int N;
 cin>>N;
 int ans=INF;
 for(int i=1;i<N;i++){
   int A=i;
   int B=N-A;
   ans=min(ans,func(A)+func(B));
 }
 cout<<ans<<endl;
  return 0;
}