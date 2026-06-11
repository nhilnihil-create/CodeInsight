#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<63)-1
#define MAX 1000000000
bool f(vector<char> &A,vector<char> &B,string &S,int X){
    X--;
    if(X<0) return 1;
    rep(i,0,A.size()){
        if(S[X]==A[i]){
            if(B[i]=='R') X++;
            else X--;
            if(X>=(int)S.size()) return 0;
            if(X<0) return 1;
        }
    }
    return 0;
}
bool g(vector<char> &A,vector<char> &B,string &S,int X){
    X=(int)S.size()-X;
    if(X>=(int)S.size()) return 1;
    rep(i,0,A.size()){
        if(S[X]==A[i]){
            if(B[i]=='R') X++;
            else X--;
            if(X>=(int)S.size()) return 1;
            if(X<0) return 0;
        }
    }
    return 0;
}
signed main(){
    int N,Q; cin>>N>>Q;
    string S; cin>>S;
    vector<char> A(Q),B(Q);
    rep(i,0,Q) cin>>A[i]>>B[i];
    int left=0,right=N;
    while(left+1<right){
        int mid=(left+right)/2;
        if(f(A,B,S,mid)) left=mid;
        else right=mid;
    }
    int ans=left;
    if(f(A,B,S,right)) ans=right;
    left=0;
    right=N;
    while(left+1<right){
        int mid=(left+right)/2;
        if(g(A,B,S,mid)) left=mid;
        else right=mid;
    }
    if(g(A,B,S,right)) ans+=right;
    else ans+=left;
    cout<<N-ans<<endl;
}