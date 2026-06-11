#include <bits/stdc++.h>
using namespace std;

// utility of stdin,stdout
#define INPS cin >>
#define BUFS cout << 
#define BUFE << endl 

int main(int argc, char const *argv[]){
	int i,win = 0,lose = 0;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); ++i)
	{
		if(s.at(i) == 'o')	++win;
		else ++lose;
	}
	if(win + (15 - i) >= 8)	BUFS("YES") BUFE;
	else BUFS("NO") BUFE;
	return 0;
}
