#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int A[100000];
    for(int i=0;i<n;i++) cin>>A[i];
    int m=0;
    for(int i=0;i<n;i++){
        if(m<A[i]) m=A[i];
    }
  if(n==2) cout<<max(A[0],A[1])<<endl<<min(A[0],A[1])<<endl;
  else{
    int p=1000000001,q;
    for(int i=0;i<n;i++){
        if(p>max(A[i]-m/2,m/2-A[i])) p=max(A[i]-m/2,m/2-A[i]),q=A[i];
    }
    cout<<m<<endl<<q<<endl;
  }
}