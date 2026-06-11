#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
    int n;cin>>n;  
    if(n==3){
        cout<<"2 5 63"<<"\n";
        return 0;
    }
    vector<int> res;
    res.push_back(3);
    res.push_back(9);
    int rem=n-2;
    int cur=2;
    while(rem>1){
        rem-=2;
        res.push_back(cur);
        res.push_back(cur+2);
        cur+=6;
        if(cur>=30000-2)break;
    }
    cur=15;
    while(rem>1){
        rem-=2;
        res.push_back(cur);
        res.push_back(cur+6);
        cur+=12;
        if(cur>=30000-6)break;
    }
    cur=6;
    while(rem>0){
        --rem;
        res.push_back(cur);
        cur+=6;
    }
    for(auto& val:res){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}