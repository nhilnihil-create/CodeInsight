#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long ll;

int n;
ll a[N], l, r;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	l = r = 2; 
    for(int i = n; i; i--) {
    	r = r - r%a[i];
    	l = l + (a[i] - l%a[i])%a[i];
    	if(r < l) {
    		cout<<-1<<endl;
    		return 0;
    	}
    	r = r + a[i] - 1;
    }
    cout<<l<<" "<<r;
	return 0;
}