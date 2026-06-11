#include<bits/stdc++.h>
using namespace std;

int n;
int a,b,c;
vector<int> l;
int ans=1000000000;

void dfs(int i,int A,int B,int C,int cal){
  if(i==n){
    if(A>0 && B>0 && C>0){
      ans=min(ans,abs(A-a)+abs(B-b)+abs(C-c)+cal);
    }
    return;
  }
  if(A>0 && B>0 && C>0) ans=min(ans,abs(A-a)+abs(B-b)+abs(C-c)+cal);
  dfs(i+1,A,B,C,cal);
  dfs(i+1,A+l[i],B,C,(A>0 ? cal+10 : cal));
  dfs(i+1,A,B+l[i],C,(B>0 ? cal+10 : cal));
  dfs(i+1,A,B,C+l[i],(C>0 ? cal+10 : cal));

}

int main(){
  cin >> n >> a >> b >> c;
  l=vector<int>(n);
  for(int i=0;i<n;++i){
    cin >> l[i];
  }
  dfs(0,0,0,0,0);

  cout << ans << endl;
  return 0;
}
