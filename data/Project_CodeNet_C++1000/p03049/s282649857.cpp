#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++)  cin >> s.at(i);
   

    ll ac=0, bc=0, either=0, cnt=0;
    for(int i=0; i<n; i++){
        if(s[i][0]=='B' && s[i].back()=='A') either += 1;
        else if(s[i].back()=='A') ac += 1;
        else if(s[i][0]=='B') bc += 1;

        for(int j=0; j<s[i].size()-1; j++)
            if(s[i][j]=='A' && s[i][j+1]=='B') cnt += 1;   
    }
    
    if(ac==0 && bc==0) cnt += max(0LL, either-1);
    else cnt += min(ac, bc) + either;
    
    cout << cnt << endl;
    
}