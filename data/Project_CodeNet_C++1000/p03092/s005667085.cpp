#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

//const int MOD=998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long a,b;
    cin>>n>>a>>b;
    
    vector<int> sp(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        sp[x]=i;
    }
    
    vector<long long> dpCur(2*n+1), dpPrev(2*n+1);
    
    for(int i=0; i<=2*n; i++){
        long long c=0;
        int goal=2*sp[1]-1;
        if(i!=goal){
            c=i<goal?b:a;
        }
        dpPrev[i]=c;
        if(i) dpPrev[i]=min(dpPrev[i],dpPrev[i-1]);
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<=2*n; j++){
            long long c=0;
            int goal=2*sp[i]-1;
            if(j!=goal){
                c=j<goal?b:a;
            }
            dpCur[j]=(j%2?dpPrev[j-1]:dpPrev[j])+c;
            if(j) dpCur[j]=min(dpCur[j],dpCur[j-1]);
        }
        dpPrev=dpCur;
    }
    cout<<dpCur[2*n];
    
    
    
    
    
    
    
    
}