#include <bits/stdc++.h>
using namespace std;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(void){
   
 string s;
 int min = 10000000;
 cin >> s;
 int len = s.size();
 
 for(int i=0;i<len-2;i++){
     int v = ctoi(s[i]) * 100 + ctoi(s[i+1]) * 10 + ctoi(s[i+2]);
     if(abs(v - 753) < min) min = abs(v - 753);
 }
 
 cout << min <<endl;
}