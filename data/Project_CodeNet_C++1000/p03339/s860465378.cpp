#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL<<50;

int main(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int totalE = 0;
    int totalW = 0;
    
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == 'E')totalE++;
        else totalW++;
    }
    
    int ans = (int)s.size();
    
    int tempE = 0;
    int tempW = 0;
    
    for (int i = 0; i < (int)s.size(); i++){
        
        int reverseE = totalE - tempE;
        if (s[i] == 'E') reverseE--;
        
        ans = min(ans, reverseE + tempW);
        
        if (s[i] == 'W') tempW++;
        else tempE++;
    }
    
    cout << ans << endl;
}