#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int rating;
	cin >> rating;
	if(rating < 1200) {
		puts("ABC");
	} else if(rating < 2800) {
		puts("ARC");
	} else {
		puts("AGC");
	}
}
