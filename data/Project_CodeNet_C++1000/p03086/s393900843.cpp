#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s; cin >> s;
    int n = s.size();
 
    int ans = 0;
    int len = 0;
    for(int i=0; i<n; i++){
        if(string("ACGT").find(s[i]) == string::npos)
            len = 0;
            
        else{
            len++;
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
 
    return 0;
}