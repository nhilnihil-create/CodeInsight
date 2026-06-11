#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1100000;

int memo[MAX_N];

int rec(int n){
    int pow6,pow9;
    if(n==0) return 0;
    if(memo[n]!=-1)return memo[n];

    int res=n;

    for(pow6=1;pow6<=n;pow6*=6){
        res=min(res,rec(n-pow6)+1);
    }

    for(pow9=1;pow9<=n;pow9*=9){
        res=min(res,rec(n-pow9)+1);
    }

    //cout<<n<<" "<<res<<endl;
    return memo[n]=res;
}

int main(){
    int N;
    cin>>N;

    for(int i=0;i<MAX_N;i++)memo[i]=-1;
    cout<<rec(N)<<endl;
}