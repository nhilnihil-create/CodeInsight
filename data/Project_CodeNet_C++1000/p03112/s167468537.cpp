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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    ll a,b,q,x;
    ll s0,s1,t0,t1;
    cin>>a>>b>>q;
    vector<ll> ans(q);
    vector<ll> s(a); for(int i=0;i<a;i++) cin>>s[i];
    vector<ll> t(b); for(int i=0;i<b;i++) cin>>t[i];
    //for(int i=0;i<a;i++) cout<<s[i]<<" ";
    //for(int i=0;i<b;i++) cout<<t[i]<<" "; 
    //cout<<endl;
    for(int i=0;i<q;i++){
        cin>>x;
        if(lower_bound(s.begin(),s.end(),x)-s.begin()==0){
            s0=-INF;
            s1=s[0];
        }else if(s[lower_bound(s.begin(),s.end(),x)-s.begin()]<x){
            s0=s[lower_bound(s.begin(),s.end(),x)-s.begin()-1];
            s1=INF;
        }else{
            s0=s[lower_bound(s.begin(),s.end(),x)-s.begin()-1];
            s1=s[lower_bound(s.begin(),s.end(),x)-s.begin()];
        }
        if(lower_bound(t.begin(),t.end(),x)-t.begin()==0){
            t0=-INF;
            t1=t[0];
        }else if(t[lower_bound(t.begin(),t.end(),x)-t.begin()]<x){
            t0=t[lower_bound(t.begin(),t.end(),x)-t.begin()-1];
            t1=INF;
        }else{
            t0=t[lower_bound(t.begin(),t.end(),x)-t.begin()-1];
            t1=t[lower_bound(t.begin(),t.end(),x)-t.begin()];
        }
        //cout<<s0<<" "<<s1<<" "<<t0<<" "<<t1<<endl;
        if(s0<=t0){
            if(s1<=t1){
                ans[i]=min(x-s0,min(x-t0+s1-t0,min(s1-x+s1-t0,t1-x)));
            }else{
                ans[i]=min(x-s0,s1-x);
            }
        }else{
            if(s1<=t1){
                ans[i]=min(x-t0,t1-x);
            }else{
                ans[i]=min(x-t0,min(x-s0+t1-s0,min(t1-x+t1-s0,s1-x)));
            }
        }
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}