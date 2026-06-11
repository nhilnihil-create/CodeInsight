#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main() {
    string s;
    cin>>s;
    int add=0;
    if(s[0]=='o')add+=100;
    if(s[1]=='o')add+=100;
    if(s[2]=='o')add+=100;
    cout<<700+add<<endl;
    return 0;
    }