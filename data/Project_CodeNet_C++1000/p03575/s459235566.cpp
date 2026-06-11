#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

struct unionfind{
    lli i;
    vector<lli> vec;
    unionfind(lli n){
        rep(i,0,n){
            vec.push_back(i);
        }
    }
    
    lli root(lli n){
        if(vec[n]==n){
            return n;
        }
        else{
            return root(vec[n]);
        }
    }
    
    void unite(lli a,lli b){
        lli ra=root(a);
        lli rb=root(b);
        if(ra!=rb){
            vec[ra]=rb;
        }
    }
    
    void reset(lli n){
        rep(i,0,n){
            vec[i]=i;
        }
    }
    
};

int main() {
    lli n,m,a,b,cnt=0;
    pair<lli,lli> dat;
    vector<pair<lli,lli>> data;
    lli i,j;
    cin>>n>>m;
    unionfind tree(n);
    rep(i,0,m){
        cin>>a>>b;
        data.push_back({a,b});
    }
    rep(i,0,m){
        tree.reset(n);
        map<lli,lli> mp;
//        cout<<data[i].first<<"ー"<<data[i].second<<"間の橋がない場合"<<endl;
        rep(j,0,m){
            if(i!=j){
                tree.unite(data[j].first-1,data[j].second-1);
            }
        }
        rep(j,0,n){
//            cout<<j+1<<"の根は、"<<tree.root(tree.vec[j])+1<<endl;
            mp[tree.root(tree.vec[j])]++;
        }
        if(mp.size()!=1){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
