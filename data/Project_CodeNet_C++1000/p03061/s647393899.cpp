#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
int main(){
    int N,ans=1;
    cin>>N;
    vector<int> A(N),L(N),R(N);
    for(int i=0;i<N;i++){cin>>A.at(i);}
    for(int i=0;i<N;i++){
        if(i==0){L.at(0)=A.at(0);}
        else{L.at(i)=gcd(A.at(i),L.at(i-1));}
    }
    for(int i=N-1;i>=0;i--){
        if(i==N-1){R.at(N-1)=A.at(N-1);}
        else{R.at(i)=gcd(A.at(i),R.at(i+1));}
    }
    for(int i=0;i<N;i++){
        if(i==0){ans=max(ans,R.at(1));}
        else if(i==N-1){ans=max(ans,L.at(N-2));}
        else{ans=max(ans,gcd(R.at(i+1),L.at(i-1)));}
    }
    cout<<ans<<endl;
}