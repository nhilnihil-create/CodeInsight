#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string S,T;cin>>S>>T;
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    reverse(T.begin(),T.end());
    int N=min(S.size(),T.size());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i]<T[j]){
                cout<<"Yes"<<endl;
                return 0;
            }
            if(S[i]==T[j]){
                break;
            }
            else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    if(S.size()<T.size()){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
