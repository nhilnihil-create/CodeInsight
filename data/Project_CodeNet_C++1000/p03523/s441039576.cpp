#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
typedef long long int ll;
using namespace std;
int main()
{
	string s;
	cin >> s;

	int f=0;
	if(s=="KIHBR")f=1;
	if(s=="AKIHBR")f=1;
	if(s=="AKIHABR")f=1;
	if(s=="AKIHBAR")f=1;
	if(s=="AKIHBRA")f=1;
	if(s=="KIHABR")f=1;
	if(s=="KIHABAR")f=1;
	if(s=="KIHABARA")f=1;
	if(s=="KIHBAR")f=1;
	if(s=="KIHBARA")f=1;
	if(s=="KIHBRA")f=1;
	if(s=="AKIHABAR")f=1;
	if(s=="AKIHABRA")f=1;
	if(s=="KIHABARA")f=1;
	if(s=="AKIHABARA")f=1;
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}