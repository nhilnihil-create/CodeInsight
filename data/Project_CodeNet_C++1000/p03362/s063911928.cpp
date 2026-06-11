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
const int inf=1e9+7;
const ll INF=1e18;

vin prime;

void eratosthenes(int x){
    vbo isprime(x+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(ll i=2;i<=x;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(ll j=2*i;j<=x;j+=i)isprime[j]=false;
        }
    }
    return;
}

int main(){
    int n;cin>>n;
    eratosthenes(55555);
    int res=0;int i=0;
    while(res<n){
        if(prime[i]%5==1){
            cout<<prime[i]<<endl;
            res++;
        }
        i++;
    }
}