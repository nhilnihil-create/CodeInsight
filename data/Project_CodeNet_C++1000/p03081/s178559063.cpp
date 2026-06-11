#include<iostream>
#include<vector>
using namespace std;

int N,Q;
string s;
vector<char> td;

bool vanish_l(int x)
{
	int pos=x;
	for(int i=0; i<Q; i++)
	{
		char t=td[2*i],d=td[2*i+1];
		if(s[pos]==t)
		{
			if(d=='L')pos--;
			else pos++;
		}
		if(pos==-1)return true;
		if(pos==N)return false;
	}
	return false;
}

bool vanish_r(int x)
{
	int pos=x;
	for(int i=0; i<Q; i++)
	{
		char t=td[2*i],d=td[2*i+1];
		if(s[pos]==t)
		{
			if(d=='L')pos--;
			else pos++;
		}
		if(pos==-1)return false;
		if(pos==N)return true;
	}
	return false;
}

int main()
{
	cin >> N >> Q >> s;
	for(int i=0; i<2*Q; i++)
	{
		char tmp;
		cin >> tmp;
		td.push_back(tmp);
	}
	int left,right,ok,ng;
	ok=-1;
	ng=N;
	while(abs(ng-ok)>1)
	{
		int mid=(ok+ng)/2;
		if(vanish_l(mid))ok=mid;
		else ng=mid;
	}
	left=ok;
	ok=N;
	ng=-1;
	while(abs(ng-ok)>1)
	{
		int mid=(ok+ng)/2;
		if(vanish_r(mid))ok=mid;
		else ng=mid;
	}
	right=ok;
	cout << right-left-1 << endl;
	return 0;
}