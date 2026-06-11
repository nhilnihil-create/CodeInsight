#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vdo=vector<double>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vvdo=vector<vector<double>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define _GLIBCXX_DEBUG
int main()
{
    int n;
    cin>>n;
    vdo x(n);
    vstr u(n);
    rep(i,n)cin>>x[i]>>u[i];
    double sum=0;
    rep(i,n){
        if(u[i]=="JPY")sum+=x[i];
        else sum+=(double)380000*x[i];
    }
    cout<<sum<<endl;
}