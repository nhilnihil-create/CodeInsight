#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	string input;
	cin>>input;
	string patokan = "AKIHABARA";
	bool valid = 1;
	if(input != patokan)
	{
		map <string , bool > cek;
		cek["KIHBR"] = 1;
		cek["AKIHBR"] = 1;
		cek["KIHABR"] = 1;
		cek["KIHBRA"] = 1;
		cek["KIHBAR"] = 1;
		cek["AKIHABR"] = 1;
		cek["AKIHABR"] = 1;
		cek["AKIHBAR"] = 1;
		cek["AKIHBRA"] = 1;
		cek["KIHABRA"] = 1;
		cek["KIHBARA"] = 1;		
		cek["AKIHABRA"] = 1;
		cek["AKIHBARA"] = 1;
		cek["AKIHABRA"] = 1;
		cek["AKIHABAR"] = 1;
		if(cek[input])
		{
			cout<<"YES\n";
		}
		else
		cout<<"NO\n";
		
		
	}
	else
	cout<<"YES\n";
	return 0;
}