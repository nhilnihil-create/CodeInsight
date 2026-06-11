#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>s;
	int n=s.size();
	bool isti=true;
	for(int i=1;i<n;i++)
        if(s[i]!=s[i-1])
            isti=false;
    if(isti)
    {
        cout<<n;
        return 0;
    }
	int k=n;
	for(int i=0;i<n/2;i++)
        if(s[i]!=s[i+1])
            k=min(k,n-i-1);
    for(int i=(n+1)/2;i<n;i++)
        if(s[i]!=s[i-1])
            k=min(k,i);
    cout<<k;
	return 0;
}
