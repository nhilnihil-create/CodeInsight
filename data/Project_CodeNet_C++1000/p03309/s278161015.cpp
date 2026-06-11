#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 200000

int N;
int A[MAXN];

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
    A[i]-=(i+1);
  }
  sort(A,A+N);
  int b=A[(N-1)/2];
  long long ans=0;
  for(int i=0;i<N;i++){
    ans+=abs(A[i]-b);
  }
  cout<<ans<<endl;
  return 0;
}
  