#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(void){
    int n; 
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 1<<30;
    int num_b = 0;
    int num_w = 0;
    
    for (int i=0; i<n; i++){
        if (s[i] == '.') num_w++;
        if(s[i] == '#') num_b++;
    }
    

    int curr_w = 0, curr_b=0;
    ans = num_w - curr_w;
    for (int i=0; i<n; i++){
        // iまでを白 i+1~nまでを黒
        if(s[i] == '.') curr_w++;
        if(s[i] == '#') curr_b++;
        // cout << curr_b + num_w - curr_w  << endl;
        ans = min(ans, curr_b + num_w - curr_w);
    }
    
    cout << ans << endl;
}
