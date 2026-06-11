#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n;cin>>n;
    vector<char>s(n);
    rep(i,n){
        cin>>s[i];
    }

    int cnt=0;
    rep(i,n){
        if(s[i]=='R'){
            cnt++;
        }
    }

    if(s.size()-cnt<cnt){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
