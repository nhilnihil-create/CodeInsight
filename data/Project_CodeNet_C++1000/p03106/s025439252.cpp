#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a,b,c;
int tot;
int main(){
	cin >> a >> b >> c;
	int minn = min(a,b);
	for(int i = minn; i > 0; i--){
		if(a % i == 0 && b % i == 0) tot++;
		if(tot == c){
			cout << i;
			return 0;
		}
	}
}
 