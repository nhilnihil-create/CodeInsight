#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

vector<int> memo(20);

int solve(int r,int d,int x,int a){
    if(a<=0) return x;
    else if(memo[a]!=0) return memo[a];
    else{
        return memo[a]=r*solve(r,d,x,a-1)-d;
    }
}

int main()
{
    int r,d,x;
    cin>>r>>d>>x;
    memo[10]=solve(r,d,x,10);
    for(int i=1;i<11;i++) cout<<memo[i]<<endl;
}