#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int f(int n){
    if(n%2==0) return n/2;
    else return 3*n+1;
}

int main(){
    int s;
    cin>>s;
    vector<int> num(1000005,0);
    
    bool exist=true;
    int i=1;
    num[s]++;
    while(exist){
        s=f(s);
        num[s]++;
        if(num[s]>1) exist=false;
        i++;
    }
    
    cout<<i<<endl;
    return 0;
}