#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    string s;
    cin>>s;

    int ans = count(s.cbegin(), s.cend(), 'o');

    cout<<700+100*ans<<endl;

    return 0;
}


