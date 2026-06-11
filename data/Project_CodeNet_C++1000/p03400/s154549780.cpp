#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,d,x;
    cin>>n>>d>>x;
    int sum=0;
    
    rep(i,n){
        int a;
        int b;
        cin>>a;
        b=1;
        while(b<=d){
            b+=a;
            sum++;
        }
    }
    
    cout<<sum+x<<"\n";
    return 0;
}