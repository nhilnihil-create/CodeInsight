/*
      author  : nishi5451
      created : 14.08.2020 18:56:30
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i=1; i<=n-1; i++){
        string l,r;
        l = s.substr(0,i);
        r = s.substr(i,n-i);
        vector<bool> dl(26,false),dr(26,false);
        rep(i,int(l.size())){
            dl[l[i]-'a']=true;
        }
        rep(i,int(r.size())){
            dr[r[i]-'a']=true;
        }
        int sum = 0;
        rep(i,26){
            if(dl[i]==true && dr[i]==true) sum++;
        }
        ans = max(sum,ans);
    }
    cout << ans << endl;
    return 0;
}