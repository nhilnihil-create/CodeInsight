#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;cin>>N;
    vector<string>W(N);
    cin>>W[0];
    for(int i=1;i<N;i++){
        cin>>W[i];
        if(W[i].at(0)!=W[i-1].at(W[i-1].size()-1)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    sort(W.begin(),W.end());
    for(int i=1;i<N;i++){
        if(W[i]==W[i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}