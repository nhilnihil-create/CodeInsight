#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;cin >> s;
	int w; cin >>w;
	string out ="";
	int pos =0;
	while(s.size()-1 >= pos){
		out += s.substr(pos,1);
		pos += w;
	}
	cout << out << endl;
	return 0;
}