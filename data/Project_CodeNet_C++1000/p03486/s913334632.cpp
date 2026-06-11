#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s,t;
    cin>>s>>t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    puts(s<t?"Yes":"No");
    return 0;
}
