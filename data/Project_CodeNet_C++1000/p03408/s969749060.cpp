#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;
int main()
{
    int n;
    cin >> n;
    
    string tmp;
    unordered_map <string, int> s, t;
    
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        s[tmp]++;
    }
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        t[tmp]++;
    }
    
    int max = 0;
    for(auto x: s)
    {
        if( max < s[x.first] - t[x.first] )
            max = s[x.first] - t[x.first];
    }
    
    cout << max;
}