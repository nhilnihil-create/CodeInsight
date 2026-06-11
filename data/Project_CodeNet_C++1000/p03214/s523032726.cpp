#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    cin>>N;
    vector<int> S(N);
    int sum=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
        sum+=S[i];
        S[i]*=N;
    }
    int www=100000,ans;
    for(int i=0;i<N;i++){
        if(abs(S[i]-sum)<www){
            www=abs(S[i]-sum);
            ans=i;
        }
    }
    cout<<ans<<endl;
}
