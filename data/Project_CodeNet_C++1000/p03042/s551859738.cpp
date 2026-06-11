#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin>> s;
	string ans;
	if((0 < s[0] - '1') || (s[0] - '1' == 0 && 0 < s[1] - '2')){
		if((0 < s[2] - '1') || (s[2] - '1' == 0 && 0 < s[3] - '2')){
			ans = "NA";
		}else{
			if(s[2] == '0'&&s[3]=='0'){
				ans = "NA";
			}else{
				ans = "YYMM";
			}
		}
	}else if((0 < s[2] - '1') || (s[2] - '1' == 0 && 0 < s[3] - '2')){
		if((0 < s[0] - '1') || (s[0] - '1' == 0 && 0 < s[1] - '2')){
			ans = "NA";
		}else{
			if(s[0] == '0'&&s[1]=='0'){
				ans = "NA";
			}else{
				ans = "MMYY";
			}
		}
	}else{
		if(s[0]=='0'&&s[1]=='0'&&s[2]=='0'&&s[3]=='0'){
			ans ="NA";
		}else{
			if(s[0] == '0'&&s[1]=='0'){
				ans ="YYMM";
			}else if(s[2] == '0'&&s[3]=='0'){
				ans = "MMYY";
			}else{
				ans = "AMBIGUOUS";
			}
		}
	}
	cout<< ans <<endl;
}