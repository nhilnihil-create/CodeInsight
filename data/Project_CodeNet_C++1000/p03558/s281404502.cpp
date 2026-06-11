//Code by 27.
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
#include<memory.h> 
#include<sstream>
#include<time.h>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const int MOD=19260817;
/*
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`  ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo,   =/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooo[o\oo\oo`  ,  ,o\o/\\ooo`ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo//\           \.          =\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`   ,\`,ooo/]`*    ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/oo`   .\ooo\[   ,/\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\^  =\\o/  ,ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  =/`  =^  =oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^            oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/    .oo/`    =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo^o=`  ,\oooo/o^   ]^ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo.]o/\oooooooo,.//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ [oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  ,/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`  ,\/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\//oooooooooooooo,   =^/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`,`o\/ooooooooooooo`   \/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/\\        ,,\/\oooooooo\^   ,\oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/^             `oooooooooo^    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo\\/             /\\ooooooooooo^    ,o\=ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooo`            /oooooooooooooooo^    ,,^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/ooo/            =o\ooooooooooooooooo`     ^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/               ,\oooooooooooooooo^\     ,ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo`                ,\[]/oooooooooooooo      ,/ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/\        ]`       ,`\oooooooooooooo^      oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo\`     \o\o        \ooooooooooooooo      =\oooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo/o=` /o/oooo^        \/\ooooooooooo      ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/o         ooooooooo\o/       ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/\        .o\ooooooo/       ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`        \/ooo\o/        ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/         \ooo^^       ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^        ./\/        oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/`        .        ,oo^ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooo.  ,ooooooooooooooo                ooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo^        `/oooooooooooo/^             oooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/\oo``           \/[ooo[ooooo^            ooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooo\,        =.        .[[[                 ,\ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o/o.       oooo\o`                             \o/\ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o.        ]oooooooo\                            ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo`        =ooooooooooooo`            ,oo/\         \ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo        =oooooooooooooooooo/oooooooooooo\/.       `ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo^^      ,ooooooooooooooooooooooooooooooooooo\    ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooo\  `,/ooooooooooooooooooooooooooooooooooooo/^ o]o/ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
*/
deque<int>dq;
int f[100005];
string st[100005];
int main()
{
	int k;
	cin>>k;
	dq.push_back(1);
	int u1;
	st[1]="1";
	for(int i=0;i<k;i++)f[i]=BIG;
	f[1]=1;
	while(!dq.empty())
	{
		u1=dq.front();
		dq.pop_front();
		if(f[(u1*10)%k]>f[u1])
		{
			//st[(u1*10)%k]=st[u1]+"0";
			dq.push_front((u1*10)%k);
			f[(u1*10)%k]=f[u1];
		}
		if(f[(u1+1)%k]>f[u1]+1)
		{
			//st[(u1+1)%k]=st[u1];
			//st[(u1+1)%k][st[(u1+1)%k].size()-1]++;
			dq.push_back((u1+1)%k);
			f[(u1+1)%k]=f[u1]+1;
		}
	}
	cout<<f[0];
	return 0;
}