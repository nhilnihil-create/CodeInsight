#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007
typedef long long ll;

int main() {
    string s;cin>>s;
    int cnt=0;
    rep(i,s.size()){
        if(s[i]=='o'){
            cnt++;
        }
    }

    if(15-s.size()+cnt>=8){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}
