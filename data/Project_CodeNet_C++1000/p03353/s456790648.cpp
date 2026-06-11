#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    string s;
    int k;
    cin>>s>>k;
    set<string> ss;
    for(int j=1;j<=k;j++){
        for(int i=0;i<s.size()-j+1;i++){
            //cout<<"Yes"<<endl;
            ss.insert(s.substr(i,j));
            //cout<<s.substr(i,j)<<endl;
        }
    }
    int cnt = 0;
    for(auto u:ss){
        cnt++;
        //cout<<u<<endl;
        if(cnt==k){
            cout<<u<<endl;
        }
    }
    return 0;
}