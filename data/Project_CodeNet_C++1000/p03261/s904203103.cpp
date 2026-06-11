#include<bits/stdc++.h>
#pragma GCC optimize('O3')
using namespace std;
typedef long long ll;
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int N;cin>>N;
    vector<string> W(N);
    rep(i,0,N)cin>>W[i];
    rep(i,1,N){
        if(W[i].front()!=W[i-1].back()){
            cout<<"No"<<endl;
            return 0;
        }
        rep(j,0,N){
            if(i==j)continue;
            if(W[i]==W[j]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}