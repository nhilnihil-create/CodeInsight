#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>
#include<map>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
	int n, h, w;cin>>n>>h>>w;
	int ans=0;
	for(int i=0;i<n;i++){
		int a, b;cin>>a>>b;
		ans+=(a>=h&&b>=w);
	}
	cout << ans << endl;
}