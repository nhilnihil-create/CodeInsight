#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ii> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

int main(){
    int n,m;cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++) cin>>a[i];
    string dp[n+10];
    for(int i=0;i<n+10;i++) dp[i]="";
    for(int i=0;i<n;i++){
        if(i!=0&&dp[i]=="") continue;
        for(int j=0;j<m;j++){
            int b;
            if(a[j]==1) b=2;
            else if(a[j]==7) b=3;
            else if(a[j]==4) b=4;
            else if(a[j]==2||a[j]==3||a[j]==5) b=5;
            else if(a[j]==6||a[j]==9) b=6;
            else if(a[j]==8) b=7;
            string t=dp[i]+(char)(a[j]+'0');
            if((int)t.size()>(int)dp[i+b].size()) dp[i+b]=t;
            else if((int)t.size()==(int)dp[i+b].size()){
                if(t>dp[i+b]) dp[i+b]=t;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}