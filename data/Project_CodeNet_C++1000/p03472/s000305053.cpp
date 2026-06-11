#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5;

int N,H;
int a,b[MAXN];

int main(){
  cin>>N>>H;
  int ma=0;
  for(int i=0;i<N;i++){
    cin>>a>>b[i];
    if(ma<a) ma=a;
  }
  sort(b,b+N,greater<int>());
  int cnt=0;
  for(int i=0;i<N;i++){
    if(b[i]<ma) break;
    if(H<=0) break;
    H-=b[i];
    cnt++;
  }
  if(H>0) cnt+=(H+ma-1)/ma;
  cout<<cnt<<endl;
  return 0;
}