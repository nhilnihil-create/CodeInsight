#include<bits/stdc++.h>
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;

//最大公約数
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int a[100010];


int main(){
    int n;cin>>n;
    string s;cin>>s;
    int ce[n],cw[n];
    if(s[0]=='W'){
            cw[0] = 1;
            ce[0] = 0;
    }else{
        cw[0] = 0;
        ce[0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if(s[i]=='W'){
            cw[i]=cw[i-1]+1;
            ce[i] = ce[i-1];
        }
        else{
            ce[i]=ce[i-1]+1;
            cw[i] = cw[i-1];
        }
    }
    int mn=ce[n-1]-ce[0];
    for (int i = 1; i < n; i++)
    {
        int num = cw[i-1]+ce[n-1]-ce[i];
        mn = min(mn,num);
    }
    cout<<mn<<endl;
return 0;
}