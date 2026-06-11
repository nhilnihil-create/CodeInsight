#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;

int main(){
    string s;cin>>s;
    int n=s.size(),t=n;
    REP(i,s.size()-1) if(s[i]!=s[i+1]){
        t=min(t,max(i+1,n-i-1));
    }
    cout<<t<<endl;
}