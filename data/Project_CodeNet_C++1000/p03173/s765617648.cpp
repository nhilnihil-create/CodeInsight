#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
const int mxN=400;
vl a(mxN+1);
vvl dp(mxN+1,vl(mxN+1,1e15)),ans(mxN+1,vl(mxN+1));
int n;
ll cost=0;

void test_case(){
    cin>>n;
    Fo(i,1,n+1){
        cin>>a[i];
    }
    Fo(len,1,n+1){
        Fo(srt,1,n+2-len){
            int end=srt+len-1;
            if(srt==end){
                dp[srt][end]=a[srt];
            }else{
                // cout<<srt<<" "<<end<<endl;
                int mid;
                for(int k=srt; k<end; k++){
                    if(dp[srt][k]+dp[k+1][end] < dp[srt][end]){
                        mid=k;
                        dp[srt][end]=dp[srt][k]+dp[k+1][end];
                    }
                    // dp[srt][end]=min(dp[srt][end],dp[srt][k]+dp[k+1][end]);
                }
                ll cost=1e15;
                for(int k=srt; k<end; k++){
                    // cout<<dp[srt][end]<<" K "<<dp[srt][k]<<" "<<dp[k+1][end]<<" "<<ans[srt][k]<<" "<<ans[k+1][end]<<endl;
                    if(dp[srt][end]==dp[srt][k]+dp[k+1][end]){
                        if((ans[srt][k]+ans[k+1][end]) < cost){
                            cost=ans[srt][k]+ans[k+1][end];
                            mid=k;
                        }
                    }
                }
                ans[srt][end]=(dp[srt][end]);
                if(srt+1<end){
                    // cout<<ans[srt][mid]<<" "<<ans[mid+1][end]<<endl;
                    ans[srt][end]+=(ans[srt][mid]+ans[mid+1][end]);
                }
                // cout<<ans[srt][end]<<" ans "<<dp[srt][end]<<" "<<mid<<endl;
            }
        }
    }
    cout<<ans[1][n]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}