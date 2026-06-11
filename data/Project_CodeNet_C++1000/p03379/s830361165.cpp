#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> X(N);
    vector<int> a(N);
    for(int i=0; i<N; i++){
        cin>>X[i];
        a[i] = X[i];
    }

    sort(X.begin(), X.end());

    for(int i=0; i<N; i++){
        if(a[i] >= X[(N+1)/2]){
            cout<<X[(N+1)/2-1]<<endl;
        }else{
            cout<<X[(N+1)/2]<<endl;
        }
    }
    return 0;
}