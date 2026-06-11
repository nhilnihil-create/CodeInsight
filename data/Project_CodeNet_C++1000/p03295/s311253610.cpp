#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> P;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
#define MAX 100000

ll n,m,a[MAX],b[MAX];
P ab[MAX] ;

int main(){

    cin>>n>>m;
    
    rep(i,m){
        cin>>a[i];
        cin>>b[i+1];
        ab[i].first=b[i+1];
        ab[i].second=a[i];
    }
    sort(ab,ab+m);
    rep(i,m){
        //cout<<ab[i].first<<" "<<ab[i].second<<endl;
    }
    int count=0;
    ll c=INT_MIN;
    rep(i,m){
        if(c<=ab[i].second){
            count++;
            c=ab[i].first;
            //cout<<ab[i].second<<endl;
        }
    }
    cout<<count; 
    
    return 0;
    
}

