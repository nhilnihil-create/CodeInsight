#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,d,x;
    cin>>n>>d>>x;
    vector<int>r(n);
    rep(i,n)cin>>r[i];
    int okasi=0;
    rep(i,n){
        for(int j=1;j<=d;j+=r[i]){
            okasi+=1;
        }
    }
    cout<<okasi+x<<endl;

}