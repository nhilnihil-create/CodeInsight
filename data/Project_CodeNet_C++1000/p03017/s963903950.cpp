#include <iostream>
#include <string>

using namespace std;

int n;
int a, b, c, d;
string s;

int main(void)
{
	cin >> n;
	cin >> a >> b >> c >> d;
	cin >> s;
	s = "#" + s + "#";
	
	int p = b; bool flag = false;
	while(1){
		if(s[p-1] == '.' && s[p+1] == '.') flag = true;
		if(p == d) break;
		if(s[p+1] == '.') p++;
		else if(s[p+2] == '.') p+=2;
		else{
			cout << "No"<< endl;
			return 0;
		}
	}
	p = a;
	while(1){
		if(p == c) break;
		if(s[p+1] == '.') p++;
		else if(s[p+2] == '.') p+=2;
		else{
			cout << "No"<< endl;
			return 0;
		}
	}
	if(d < c && !flag) cout << "No" <<endl;
	else cout << "Yes" << endl;
	
	return 0;
}
