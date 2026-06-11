#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
string s;
int cx[8005],cy[8005],cntx,cnty,cntfx,cntfy,x,y,px,py,dx,dy,allx,ally;
bool isx=1;
set<int>reachx[8005],reachy[8005];
inline bool checkx(int now) {
	reachx[0].insert(0);
	for(int i=1;i<=cntx;i++)
		for(set<int>::iterator it=reachx[i-1].begin();it!=reachx[i-1].end();it++)
			reachx[i].insert(*it+cx[i]),reachx[i].insert(*it-cx[i]);
	return reachx[cntx].count(now);
}
inline bool checky(int now) {
	reachy[0].insert(0);
	for(int i=1;i<=cnty;i++)
		for(set<int>::iterator it=reachy[i-1].begin();it!=reachy[i-1].end();it++)
			reachy[i].insert(*it+cy[i]),reachy[i].insert(*it-cy[i]);
	return reachy[cnty].count(now);
}
int main() {
	cin>>s;
	read(x);read(y);
	int pos=0;
	while(s[pos]=='F')
		px++,pos++;
	for(int i=pos;i<s.length();i++) {
		if(s[i]=='F'&&isx)
			cntfx++;
		else if(s[i]=='F'&&!isx)
			cntfy++;
		else {
			if(isx) {
				cx[++cntx]=cntfx;
				cntfx=0;
				isx=0;
			}
			else if(!isx) {
				cy[++cnty]=cntfy;
				cntfy=0;
				isx=1;
			}
		}
	}
	if(isx) {
		cx[++cntx]=cntfx;
		cntfx=0;
		isx=0;
	}
	else if(!isx) {
		cy[++cnty]=cntfy;
		cntfy=0;
		isx=1;
	}
	dx=abs(x-px);
	dy=abs(y-py);
//	cout<<dx<<" "<<dy<<" "<<allx<<" "<<ally<<endl;
	if(checkx(dx)&&checky(dy))
		puts("Yes");
	else
		puts("No");
}