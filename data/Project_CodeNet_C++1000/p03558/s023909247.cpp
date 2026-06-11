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
vector<pair<int,int> >vt[100001];
int f[100001];
int main()
{
	int k;
	cin>>k;
	priority_queue<pair<int,int> >que;
	que.push(make_pair(0,1));
	for(int i=0;i<=100000;i++)f[i]=-BIG;
	f[1]=0;
	pair<int,int>u;
	while(!que.empty())
	{
		u=que.top();
		que.pop();
		if(f[(u.second*10)%k]<u.first)
		{
			f[(u.second*10)%k]=u.first;
			que.push(make_pair(u.first,(u.second*10)%k));
		}
		if(f[(u.second+1)%k]<u.first-1)
		{
			f[(u.second+1)%k]=u.first-1;
			que.push(make_pair(u.first-1,(u.second+1)%k));
		}
	}
	cout<<-f[0]+1;
	return 0;
}