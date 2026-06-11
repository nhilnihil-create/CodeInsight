#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
	
	int n;
	
	scanf("%d", &n);
	
	if (n%2==0){
		printf("%d\n", n);
	}
	else{
		printf("%d\n", n*2);
	}

    return 0;
}
