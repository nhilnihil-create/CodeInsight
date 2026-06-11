#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    string s;
    cin>>s;

    sort(s.begin(), s.end());

    cout<<((s[0]=='a' && s[1]=='b' && s[2]=='c')? "Yes":"No")<<endl;


    return 0;
}