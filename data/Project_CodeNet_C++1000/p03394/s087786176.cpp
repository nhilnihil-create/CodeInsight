#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n;

int main(){
    cin>>n;
    if(n==3){
        cout<<"2 3 25\n";
        return 0;
    }
    int a=min(n/2-1,2500);
    int b=n-2*a,c=b%3;
    b-=c;
    rep(i,a){
        if(i)cout<<" ";
        cout<<i*12+3<<" "<<i*12+9;
    }
    rep(i,b){
        cout<<" "<<i*2+2;
    }
    if(c==0)cout<<endl;
    if(c==1)cout<<" 30000\n";
    if(c==2)cout<<" 29996 29998\n";
}