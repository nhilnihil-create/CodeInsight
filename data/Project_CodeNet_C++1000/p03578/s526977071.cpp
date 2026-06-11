#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    long long N;cin>>N;
    vector<long long>D(N);
    for(long long i=0;i<N;i++){
        cin>>D[i];
    }
    sort(D.begin(),D.end());
    long long M;cin>>M;
    if(N<M){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<long long>T(M);
    for(long long i=0;i<M;i++){
        cin>>T[i];
    }
    sort(T.begin(),T.end());
    long long tmp=0,count=0;
    for(long long i=0;i<N;i++){
        if(D[i]!=T[count]){
            continue;
        }
        count++;
        tmp++;
    }
    if(tmp==M){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}
