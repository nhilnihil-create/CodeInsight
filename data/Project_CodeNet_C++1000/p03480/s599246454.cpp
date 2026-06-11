# include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; 
    cin >> s;
    int ans = 2147483647; 
    for(int i = 1;i < s.size();i++) 
        if(s[i] != s[i-1]) 
            ans = min(ans,max(i,int(s.length())-i));
    cout << min(ans , int(s.size())) <<endl;
    return 0;
}