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
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int N,A,B,C;
vector<int> l;
const long int INF=100000;

int dfs(int n,int a,int b,int c){
    if (n==N){
        if (a==0||b==0||c==0) return INF;
        else return abs(A-a)+abs(B-b)+abs(C-c);
    }
    return min({dfs(n+1,a,b,c),dfs(n+1,a+l[n],b,c)+(a?10:0),dfs(n+1,a,b+l[n],c)+(b?10:0),dfs(n+1,a,b,c+l[n])+(c?10:0)});
}

int main(){
    cin>>N>>A>>B>>C;
    for (int i=0;i<N;i++){
        int x;
        cin>>x;
        l.push_back(x);
    }
    cout<<dfs(0,0,0,0)<<endl;
    return 0;
}