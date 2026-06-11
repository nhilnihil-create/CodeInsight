#include <iostream>
#include <string>

using namespace std;
int main()
{
	int a,i;
	string st;
	cin >> st >> a;
	for(i=0; i<st.size(); i+=a)
		cout << st[i];
}
