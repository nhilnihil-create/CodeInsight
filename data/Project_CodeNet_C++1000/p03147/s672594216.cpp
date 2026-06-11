#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
int n, arr[105], cnt=0;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	cnt=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>=arr[i-1]){
			cnt+=arr[i]-arr[i-1];
		}
	}
	printf("%d\n", cnt);
}
