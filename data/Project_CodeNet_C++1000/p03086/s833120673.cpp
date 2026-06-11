/*
      author  : nishi5451
      created : 15.08.2020 00:04:11
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    vector<int> a;
    a.push_back(-1);
    rep(i,int(s.size())){
        if(s[i]!='A' && s[i]!='C' && s[i]!='G' && s[i]!='T'){
            a.push_back(i);
        }
    }
    a.push_back(s.size());
    int ans = 0;
    rep(i,int(a.size())-1){
        
        ans = max(ans,a[i+1]-a[i]-1);
    }
    cout << ans << endl;
    return 0;
}