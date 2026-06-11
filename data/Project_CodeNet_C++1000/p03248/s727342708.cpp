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
    if(s[0]!='1' || s[n-1]!='0')
    {
        cout<<-1;
        return 0;
    }

    int m=n-2;
    for(int i=1;i<=m/2;i++)
        if(s[i]!=s[m-i])
        {
            cout<<-1;
            return 0;
        }

    int posl=1;
    for(int i=2;i<=n;i++)
    {
        cout<<posl<<" "<<i<<endl;
        if(s[i-2]=='1')
            posl=i;
    }

	return 0;
}
