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
    if(k==1){
        cout<<(ll)n*n*n<<endl;
        return 0;
    }
    vin r(k,0);
    if(n<k)rep(i,n)r[i+1]=1;
    else{
        rep(i,k)r[i]=n/k;
        rep(i,n%k)r[i+1]++;
    }
    if(k%2){
        cout<<(ll)r[0]*r[0]*r[0]<<endl;
        return 0;
    }
    cout<<(ll)r[0]*r[0]*r[0]+(ll)r[k/2]*r[k/2]*r[k/2]<<endl;

}
