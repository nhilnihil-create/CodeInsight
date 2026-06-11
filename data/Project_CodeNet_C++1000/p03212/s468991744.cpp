#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
ll ans=0;

ll s_to_i(string s){
    int n=s.length();
    ll res=0;
    for(int i=n-1;i>=0;i--){
        ll now=s[n-1-i]-'0';
        res+=now*pow(10,i);
    }
    return res;
}

bool che753(string s){
    bool sev=false, fiv=false, thr=false;
    for(char c:s){
        if(c=='3') thr=true;
        if(c=='5') fiv=true;
        if(c=='7') sev=true;
    }
    if(sev && fiv && thr) return true;
    return false;
}
void dfs(string s,ll n){
    if(s_to_i(s)>n){
        //cout<<s<<" ="<<s_to_i(s)<<endl;
        return;
    }
    if(s.length()>0 && che753(s)){
        //cout<<s<<endl;
        ans++;
    }
    string s7=s+"7";
    string s5=s+"5";
    string s3=s+"3";
    dfs(s7,n);
    dfs(s5,n);
    dfs(s3,n);
    return;
}

int main(){
    ll n;
    cin>>n;
    string s="";
    dfs(s,n);
    cout<<ans<<endl;
}