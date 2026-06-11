#include <iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>
#define ll  long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

/*ll ma=998244353;
ll power(ll v,ll ti){
if(ti==1)
    return v;
ll x=power(v,ti/2);
x=(x*x)%ma;
if(ti%2==1)
    x=(x*v)%ma;
return x;

}
struct t{
int a,b;
};
vector<vector<t > >g;
vector<int> v;


ll n;


void dfs(int i,int sum){
v[i]=1;


for(int j=0;j<go[i].size();j++){
    int x=go[i][j].a;
    int y=go[i][j].b;
    if(v[x]==0){
        dfs(x,min(y,sum));

    }

}

}*/



 int main(){
ll n,k;
cin>>n>>k;
if(n-k>=0)
    cout<<n-k+1<<endl;
else
    cout<<0<<endl;

 }
