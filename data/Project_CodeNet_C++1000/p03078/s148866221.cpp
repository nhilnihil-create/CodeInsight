#include<bits/stdc++.h>
#define int long long
using namespace std;
struct S{int a,b,c,d;};
bool operator<(S a,S b){
  if(a.a!=b.a)return a.a<b.a;
  if(a.b!=b.b)return a.b<b.b;
  if(a.c!=b.c)return a.c<b.c;
  return a.d<b.d;
}
bool operator==(S a,S b){
  return a.a==b.a && a.b==b.b && a.c==b.c && a.d==b.d;
}
signed main(){
  int X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<int> A(X),B(Y),C(Z);
  for(int &i:A)cin>>i;
  for(int &i:B)cin>>i;
  for(int &i:C)cin>>i;
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  priority_queue<S> Q;
  Q.push(S{A[X-1]+B[Y-1]+C[Z-1],X-1,Y-1,Z-1});
  S n{-1,-1,-1,-1};
  for(int i=0;i<K;){
    S a=Q.top();
    Q.pop();
    if(a==n)continue;
    n=a;
    if(a.b)Q.push(S{a.a-A[a.b]+A[a.b-1],a.b-1,a.c,a.d});
    if(a.c)Q.push(S{a.a-B[a.c]+B[a.c-1],a.b,a.c-1,a.d});
    if(a.d)Q.push(S{a.a-C[a.d]+C[a.d-1],a.b,a.c,a.d-1});
    cout<<a.a<<endl;
    i++;
  }
}