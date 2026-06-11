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
    int n,k;cin>>n>>k;
    vin a(n);
    int madd;
    rep(i,n){
        cin>>a[i];
        if(a[i]==1)madd=i;
    }
    int min=inf;
    rep(i,k){
        if(((madd-i)+(k-1)-1)/(k-1)+((n-madd+i-k)+(k-1)-1)/(k-1)<min)min=(madd-i+k-2)/(k-1)+(n-madd+i-2)/(k-1);
    }
    cout<<min+1<<endl;
}