#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    string s;cin>>s;
    ll ans=0;
    ll c=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='W'){
            ans+=i;
            c++;
        }
    }
    ans-=(c-1)*c/2;
    cout<<ans<<endl;
    return 0;
}