#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define For(i,a,n) for(i=a;i<n;i++)
#define all(ar) ar.begin(),ar.end() 
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
const ll mod = 1000000007;

int waes(int t,int a,int b){
    if(a > b) swap(a,b);
    int i,r = t/a, ans = 0;
    For(i,0,r+1){
        int x = i * a;
        if((t-x) % b == 0) ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //*/
    int a,b,c,n,i,ans = 0;
    cin>>a>>b>>c>>n;
    int t = n/c;
    For(i,1,t+1){
        int k = n - (i*c);
        ans += waes(k,a,b);
    }
    ans += waes(n,a,b);
    cout<<ans;
    return 0;
}