#include <bits/stdc++.h>
using namespace std;
string str;
void solve()
{
    vector < int > tag(3,0);
    int i,len=str.length();
    for (i=0;i<len;i++)
        tag[str[i]-'a']++;
    sort(tag.begin(),tag.end());
    if (tag[1]-tag[0]>1||tag[2]-tag[0]>1) cout<<"NO";
    else cout<<"YES";
    cout<<endl;
}
int main()
{
    while(cin>>str)
        solve();
}