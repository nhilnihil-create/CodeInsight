#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

string s;
int dp[330][330][330];

int f(int st,int en,int k){
    if(st >en)return 0;
    if(st == en){
        return 1;
    }
    int &ret = dp[st][en][k];
    if(ret != -1)return ret;
    int r =0;
    r = max(r,f(st+1,en,k));
    r = max(r,f(st,en-1,k));

    if(k ||(s[st] == s[en]))
        r = max(r,f(st+1,en-1,k-(s[st] != s[en]))+2);

    return ret = r;
}

int v[100100];
int main()  {
    int k;
    ios::sync_with_stdio(0);
    cin>>s>>k;
    int n = s.size();
    memset(dp,-1,sizeof dp);

    int mx =f(0,n-1,k);
    cout<<mx<<endl;
    return 0;
}
