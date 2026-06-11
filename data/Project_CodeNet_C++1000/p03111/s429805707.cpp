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
    int n,a,b,c;cin>>n>>a>>b>>c;
    vin l(n);
    rep(i,n)cin>>l[i];
    int min=inf;
    rep(i,1<<16){
        bitset<16> tmp(i);
        int suma=0;int sumb=0;int sumc=0;
        int faca=0;int facb=0;int facc=0;
        int sum=0;
        for(int j=0;j<16;j+=2){
            if(tmp[j]==0&&tmp[j+1]==0){
                suma+=l[j/2];
                faca++;
            }
            else if(tmp[j]==0&&tmp[j+1]==1){
                sumb+=l[j/2];
                facb++;
            }
            else if(tmp[j]==1&&tmp[j+1]==0){
                sumc+=l[j/2];
                facc++;
            }
        }
        if(!faca||!facb||!facc)continue;
        sum=10*(faca+facb+facc-3)+abs(a-suma)+abs(b-sumb)+abs(c-sumc);
        if(sum<min)min=sum;
    }
    cout<<min<<endl;
}