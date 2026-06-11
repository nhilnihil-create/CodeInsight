#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    string s,t; cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    if(s<t) cout << "Yes" << endl;
    else cout << "No" << endl;
}