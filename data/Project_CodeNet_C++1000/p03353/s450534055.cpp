//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    string s;
    ll k; cin>>s>>k;
    map<string,ll>mp;
    ll num=s.size();
    ll cnt=0;
    for(char c='a';c<='z';c++){
        for(int i=0;i<num;i++){
            if(s[i]==c){
                for(int j=1;j<=min(k,num-i);j++){
                    
                    mp[s.substr(i,j)]++;
                    if(mp[s.substr(i,j)]>1)continue;
                    else cnt++;
                }
            }
        }
        if(cnt>=k)break;
    }
    ll CNT=1;
    for(auto p:mp){
        if(CNT==k){
            cout<<p.first<<endl;
            return 0;
        }
        else CNT++;
    }
}









