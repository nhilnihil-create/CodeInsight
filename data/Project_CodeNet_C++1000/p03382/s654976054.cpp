#include <iostream>
#include <algorithm>
#define INF 10000000000

using namespace std;
int main(void){
    int N;
    cin>>N;
    long A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A,A+N);
    if(N!=2){
      long min=INF; long ans=0;
      for(int i=0;i<N-1;i++){
          if(min>abs(A[N-1]-2*A[i])){min=abs(A[N-1]-2*A[i]); ans=A[i];}
      }
      cout<<A[N-1]<<' '<<ans;
    }
    else {cout<<A[1]<<' '<<A[0];}
    return 0;
}
