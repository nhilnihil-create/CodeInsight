#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	if(s=="AKIHABARA"){cout << "YES" << endl;return 0;}
	else if(s=="KIHBR"){cout << "YES" << endl;return 0;}
	
	else if(s=="AKIHBR"){cout << "YES" << endl;return 0;}
	else if(s=="KIHABR"){cout << "YES" << endl;return 0;}
	else if(s=="KIHBAR"){cout << "YES" << endl;return 0;}
	else if(s=="KIHBRA"){cout << "YES" << endl;return 0;}
	
	else if(s=="KIHABARA"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHBARA"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHABRA"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHABAR"){cout << "YES" << endl;return 0;}
	
	else if(s=="KIHBARA"){cout << "YES" << endl;return 0;}
	else if(s=="KIHABRA"){cout << "YES" << endl;return 0;}
	else if(s=="KIHABAR"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHBRA"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHBAR"){cout << "YES" << endl;return 0;}
	else if(s=="AKIHABR"){cout << "YES" << endl;return 0;}
	
	else {cout << "NO" << endl;return 0;}
	
	return 0;
}
