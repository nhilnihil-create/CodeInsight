#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    ll N;cin>>N;
    string s;cin>>s;
    map<char,int> m;
    rep(i,0,N){
        m[s.at(i)]++;
    }
    ll ans=1;
    for(char i='a';i<='z';i++){
        ans=((m[i]+1)*ans)%1000000007;
    }
    cout<<ans-1<<endl;
}




