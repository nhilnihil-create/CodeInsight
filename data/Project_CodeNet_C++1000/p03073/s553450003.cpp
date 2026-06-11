#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
#define sz(a) int(a.size())
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
#define lson l,mid,p<<1
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
const double eps=1e-8;
const int mod=1e9+7;
const int N=1e5+10;
const int inf=1e9;
char s[N];
int n;
int main(){
    //ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    scanf("%s",s);
    n=strlen(s);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(i%2!=s[i]-'0') x++;
        else y++;
    }
    cout<<min(x,y)<<endl;
    return 0;
}