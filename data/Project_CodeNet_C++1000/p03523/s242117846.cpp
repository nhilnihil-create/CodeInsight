#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin>>s;
	if (s.size()<5) return puts("NO"),0;
	int pos = s.find("KIH");
	if (pos<0||pos>1) return puts("NO"),0;
	if (pos==0) s.insert(0,"A");
	pos = s.find("B");
	if (pos<0||pos!=5&&pos!=4) return puts("NO"),0;
	if (pos==4) s.insert(4,"A");
	pos = s.find("R");
	if (pos<0||pos!=7&&pos!=6) return puts("NO"),0;
	if (pos==6) s.insert(6,"A");
	if (s.back()!='A') s.push_back('A');
	puts(s=="AKIHABARA"?"YES":"NO");
}





