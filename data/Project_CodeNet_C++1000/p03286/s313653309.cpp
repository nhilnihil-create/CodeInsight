#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
#define _GLIBCXX_DEBUG
const int inf=1e9+7;

int main(){
    int n;cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    vin s(1000);
    ll fac=2;
    int i=0;
    while(n){
        if(n%fac)s[i]=1;
        else s[i]=0;
        if(n%fac){
            if(i%2)n+=pow(2,i);
            else n-=pow(2,i);
        }
        fac*=2;
        i++;
    }
    for(int j=i-1;j>=0;j--)cout<<s[j];
    cout<<endl;
}