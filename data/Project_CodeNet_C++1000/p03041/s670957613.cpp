#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;


int main(void){
    int n,k;
    string s;
    cin>>n>>k>>s;
    s[k-1]+='a'-'A';
    cout<<s<<endl;
    return 0;
}