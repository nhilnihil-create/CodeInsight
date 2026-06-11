#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x){
    if(x == 1)  return 1;
    return f(x/2)*2+1;
}

int main(){
    string s;
    cin >> s;
    
    int ans(1000);
    for(int i=0;i<s.size()-2;i++){
        string t = s.substr(i,3);
        int num = atoi(t.c_str());
        ans = min(ans,abs(num-753));
    }
    
    cout << ans << endl;
    
    return 0;
}
