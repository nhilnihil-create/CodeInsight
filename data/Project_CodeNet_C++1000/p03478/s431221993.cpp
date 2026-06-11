#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    
    int ans(0);
    for(int i=1;i<=n;i++){
        string s = to_string(i);
        int sum(0);
        for(int i=0;i<s.size();i++){
            sum += s[i]-'0';
        }
        if(sum>=a && sum<=b)
            ans += i;
    }
    
    cout << ans << endl;
    return 0;
}
