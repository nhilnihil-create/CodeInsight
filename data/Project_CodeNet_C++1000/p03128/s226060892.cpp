#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#define inf 10e8
#define rep(i,n) for(long i=0;i<n;i++)
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<long> vec(m);
    long num[n+10];
    num[1]=2;num[2]=5;num[3]=5;num[4]=4;num[5]=5;num[6]=6;num[7]=3;num[8]=7;num[9]=6;
    rep(i,m) cin >> vec[i];
    //dp 桁数
    long dp[n+10];
    dp[0]=0;dp[1]=-inf;
    for(int i=2;i<=n;i++){
        long counter;
        dp[i]=-inf;
        for(int j=0;j<m;j++){
            long honsuu=0;
            counter=i-num[vec[j]];
            if(counter<0) {
                honsuu=-inf;
            }
            else{
                honsuu=dp[counter]+1;
            }
            dp[i]=max(dp[i],honsuu);
        }
    }
    
    //making
    queue<long> que;
    sort(vec.begin(),vec.end(),greater<int>());
    long e=n;
    while(e>0){
        for(int i=0;i<m;i++){
            if(e-num[vec[i]]<0) continue;
            else if(dp[e]-1==dp[e-num[vec[i]]]){
                que.push(vec[i]);
                e=e-num[vec[i]];
                break;
            }
        }
    }
    ostringstream ans;
    
    while(!que.empty()){
        long d=que.front();
        que.pop();
        ans << d;
    }
    printf("%s\n",ans.str().c_str());
}


