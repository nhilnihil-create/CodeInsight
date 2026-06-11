#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N,K;
    cin>>N>>K;
    vector<int> x(N);
    int ans=1<<29;
    for(int i=0;i<N;i++){
            cin>>x[i];
      	if(i>=K-1){
         	ans=min(ans,(x[i]-x[i-K+1])+min(abs(x[i]),abs(x[i-K+1])));
        }
    }               
    cout<<ans<<endl;
    return 0;
}