#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    string s, t="";   cin >> s;
    int n=s.size(), ans=0;
    
    for(int i=0; i<n; i++)
        if(s[i]!='x') t += s[i];
    string bef = t.substr(0,t.size()/2), aft;
    reverse(t.begin(), t.end());
    aft=t.substr(0, t.size()/2);

    if(bef==aft){
        vector<ll> xcnt(t.size()+1, 0);
        int index=0;
        for(int i=0; i<n; i++){
            if(s[i]=='x') xcnt[index] += 1;
            else index += 1;
        }
        for(int i=0; i<=t.size()/2; i++)
            ans += abs(xcnt[i]-xcnt[t.size()-i]);
    }else ans=-1;
    cout << ans << endl;
}

