#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int ct=0;
	for (char ch : s)
		if (ch=='2') ct++;
	cout<<ct<<endl;
	return 0;
}
