#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int big = max(a, max(b, c));
	int small = min(a, min(b, c));
	int mid = a+b+c-big-small;
	int b_m = big-mid;
	int m_s = mid - small;
	int co =0;
	if(m_s%2 == 0){
		co += m_s/2;
		co += b_m;
	}else{
		co += (m_s+1)/2;
		co += (b_m+1);
	}
	cout << co << endl;
}
