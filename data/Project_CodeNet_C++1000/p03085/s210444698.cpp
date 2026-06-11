#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
#define pb push_back

/*int pare(int en,int start,int par[])
{
	if(par[en]==start)
	{
		return en;
	}
	pare(par[en],start,par);
}*/

int main()
{
    int tst=1;
    //scanf("%d",&tst);
    while(tst--)
    {
		char c;
		cin >> c;
		map<char,char>mp;
		mp['A']='T';
		mp['T']='A';
		mp['C']='G';
		mp['G']='C';
		cout << mp[c] << endl;
    }
    return 0;
}
