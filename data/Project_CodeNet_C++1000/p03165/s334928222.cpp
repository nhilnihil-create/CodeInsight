#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define pii pair<int,int>
const int mod=1e9+7;
int lcs[3001][3001];
int solve(int i,int j,string &s,string &t){
    if(i<0 || j<0) return 0;
    if(lcs[i][j]!=-1) return lcs[i][j];
    if(i==0 || j==0) lcs[i][j]=0;
    else if(s[i-1]==t[j-1]){
        lcs[i][j]=1+solve(i-1,j-1,s,t);
        int t1=solve(i-1,j,s,t);
        t1=solve(i,j-1,s,t);
    }
    else{
        lcs[i][j]=max(solve(i-1,j,s,t),solve(i,j-1,s,t));
    }
    return lcs[i][j];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
#endif
    
    string s,t;
    cin>>s>>t;
    memset(lcs,-1,sizeof(lcs));
    int n=s.length(),m=t.length();
    //cout<<n<<" "<<m<<"\n";
    int len=solve(n,m,s,t);
    char ans[len];
    int i=n,j=m,k=len-1;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            //cout<<s[i];
            ans[k]=s[i-1];
            k--;
            i--;
            j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1]) i--;
        else j--;
    }
    for(int i=0;i<len;i++){
        cout<<ans[i];
    }
    return 0;
}