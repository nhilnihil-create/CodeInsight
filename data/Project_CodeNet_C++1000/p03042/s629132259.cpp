#include <bits/stdc++.h>
using namespace std;
int main() {
	int s,a,b; cin>>s,a=s/100,b=s%100;
	cout<<(0<a&&a<13?00<b&&b<13?"AMBIGUOUS":"MMYY":00<b&&b<13?"YYMM":"NA");
}