#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    vector<int> A(3);
    
    rep(i,3){
        cin>>A[i];
    }
    
    sort(A.begin(),A.end());
    int ans=abs(A[0]-A[1])+abs(A[1]-A[2]);
    cout<<ans<<endl;
    
  
}