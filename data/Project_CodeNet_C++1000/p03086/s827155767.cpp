#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	char s[12];
	cin >> s;
	int i, count = 0, temp = 0;
	int l = strlen(s);
	for(i=0; i<l; i++){
		if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T'){
			temp++;
		}
		else{
			count = max(temp, count);
			temp = 0;
		}
	}
	count = max(count, temp);
	cout << count << endl;
	return 0;
}
