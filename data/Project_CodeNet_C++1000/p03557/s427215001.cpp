#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (long int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int main(){
    long int N;
    cin>>N;
    vector<vector<long int> > A(3,vector<long int>(N));
    rep(i,3){
        rep (j,N) cin>>A[i][j];
    }
    rep(i,3) sort(A[i].begin(),A[i].end());
    long int n=0;
    long long ans=0;
    rep (i,N){
        while (n<N && A[1][n]<A[2][i]){
            auto it=lower_bound(A[0].begin(),A[0].end(),A[1][n]);
            n++;
            long int nn=it-A[0].begin();
            ans+=nn*(N-i);
        }
    }
    cout<<ans<<endl;

    return 0;
}