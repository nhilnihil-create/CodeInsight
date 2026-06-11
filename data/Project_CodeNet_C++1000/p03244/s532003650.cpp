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
    bool can=true;
    vin v(n);
    rep(i,n){
        cin>>v[i];
        if(can&&i){
            if(v[i]!=v[0])can=false;
        }
    }
    if(can){
        cout<<n/2<<endl;
        return 0;
    }
    vin even (100001);
    vin odd(100001);
    rep(i,n){
        if(i%2)odd[v[i]]++;
        else even[v[i]]++;
    }
    int maxeven=*max_element(all(even));
    int maxodd=*max_element(all(odd));
    int evenadd;
    int oddadd;
    rep(i,100001){
        if(even[i]==maxeven)evenadd=i;
        if(odd[i]==maxodd)oddadd=i;
    }
    if(evenadd!=oddadd){
        cout<<n-maxeven-maxodd<<endl;
        return 0;
    }
    else{
        even[evenadd]=0;
        odd[oddadd]=0;
        int seceven=*max_element(all(even));
        int secodd=*max_element(all(odd));
        if(seceven==0)cout<<n-maxeven-secodd<<endl;
        else if(secodd==0)cout<<n-maxodd-seceven<<endl;
        else cout<<n-max(maxodd+seceven,maxeven+secodd)<<endl;
    }
}