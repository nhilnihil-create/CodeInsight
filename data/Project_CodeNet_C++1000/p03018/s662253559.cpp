#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;
	ll cnt=0;
	ll sol=0;
	char tek,pret;
	for(int i=0;i<s.size();i++)
    {
        tek=s[i];
        if(tek=='A') cnt++;
        if(tek=='A' && pret=='B') cnt=1;
        if(tek=='B' && pret=='B') cnt=0;
        if(tek=='C' && pret=='B') sol+=cnt;
        if(tek=='C' && pret!='B') cnt=0;
        pret=tek;
    }
    cout<<sol;

	return 0;
}
