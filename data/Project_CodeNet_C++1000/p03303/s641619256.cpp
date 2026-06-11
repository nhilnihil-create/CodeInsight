#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    string s;cin>>s;
    int w;cin>>w;
    int x=0;

    while(x<s.size()){
        cout<<s[x];
        x+=w;
    }
    cout<<endl;
}

