#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	static int n;
	static int a[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	
	int x = 0;
	for(int i = 0 ; i < n ; i ++){
		x = max( x , a[i] );
	}
	int y = 0;
	for(int i = 0 ; i < n ; i ++){
		if(min(y,x-y) < min(a[i],x-a[i])){
			y = a[i];
		}
	}
	cout << x << " " << y << endl;
}

