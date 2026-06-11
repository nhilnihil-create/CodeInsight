#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<tuple<string,int,int> > A(n);
  for(int i=0;i<n;i++){
    cin>>get<0>(A[i]);
    int ss;
    cin>>ss;
    get<1>(A[i])=100-ss;
    get<2>(A[i])=i+1;
  }
  sort(A.begin(),A.end());
  for(int i=0;i<n;i++){
    printf("%d\n",get<2>(A[i]));
  }
}