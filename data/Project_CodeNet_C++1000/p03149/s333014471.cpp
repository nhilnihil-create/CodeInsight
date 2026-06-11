#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main(){
	a.resize(4);
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	sort(a.begin(),a.end());puts(a==vector<int>{1,4,7,9}?"YES":"NO");
}