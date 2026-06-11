#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int common( map<char,int> small , map<char,int> large  )
{
    int ans =0;
    map<char,int> :: iterator  it = small.begin();
    while( it != small.end()  )
    {
        char t = it->first;
        if( large[t] > 0 )
        {
            ans++;
        }
        it++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char , int> large , small;
    for(int i=0;i<n;i++)
    {
        large[s[i] ]++;
    }
    int ans =0;
    for(int i=0;i<n;i++)
    {
        small[ s[i]] ++;
        large [ s[i]]--;
        ans = max(ans , common(small , large));
    }
    cout<<ans;
}