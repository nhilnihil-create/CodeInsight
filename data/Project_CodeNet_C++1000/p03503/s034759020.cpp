#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    int f[n+1][11];
    int p[n+1][11];
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=10; j++){
            cin>>f[i][j];
        }
    }
    
    for (int i=1; i<=n; i++){
        for (int j=0; j<=10; j++){
            cin>>p[i][j];
        }
    }
    
    ll ans=-100000000000;
    for (int bit = 1; bit < (1<<10); ++bit){
        vector<int> S;
        for (int i = 0; i < 10; ++i) {
            if (bit & (1<<i))  S.push_back(1);
            else S.push_back(0);
        }
        
        int day[n+1];
        for (int i=1; i<=n; i++) day[i]=0;
        
        for (int i=1; i<=n; i++){
            for (int j=0; j<10; j++){
                if (S[j]==1 && f[i][j+1]) day[i]++;
            }
        }
        
        
        
        ll sum=0;
        for (int i=1; i<=n; i++){
            sum+=p[i][day[i]];
        }
  
        ans=max(sum,ans);
    }
    
    cout<<ans<<endl;
}