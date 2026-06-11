#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;
#define rep(s,i,n) for(int i=s;i<n;i++)
#define c(n) cout<<n<<endl;
#define ic(n) int n;cin>>n;
#define sc(s) string s;cin>>s;
#define mod 1000000007
#define f first
#define s second
#define int long long
int a[114514];
int ans[114514];
bool p(int x){
	if(x==1)return false;
	rep(2,i,x){
		if(x%i==0)return false;
	}
	return true;
}		
signed main(){
    ic(n)
    rep(0,i,n)cin>>a[i];
    int renzoku,ans=0;
    rep(0,i,n){
        if(a[i]==a[i+1])renzoku++;
        else{
            ans+=(renzoku+1)/2;
            renzoku=0;
        }
    }
    c(ans)
}
            