#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>

using namespace std;


int main() {
	int n, s[200] = {}, num[200] = {}, result = 0, lamp = 1, in, ax, h, w, m, a, b, c, d, r, tmp=1;
	string str ,str2;
	cin >>str;
	n = str.length();
	in = n;
  	tmp=n;
	for (int i = 1; i < n; i++) {
        
		if (str[i] != str[i - 1]) { tmp = max(i, n - i); }
		if (tmp < in) { in = tmp; }
    
	}
	cout << in;
	

}