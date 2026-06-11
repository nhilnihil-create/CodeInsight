#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+5;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    
    for(auto &it:a)
    {
        cin >> it;
    }
    
    vector<bool> dp(k+1,false);
    
    for(int stones=0;stones<=k;++stones)
    {
        for(auto k:a)
        {
            if(k<=stones && dp[stones-k]==false)
            dp[stones]=true;
        }
    }
    cout << (dp[k]?"First":"Second") ;
    
    return 0;
    
}
