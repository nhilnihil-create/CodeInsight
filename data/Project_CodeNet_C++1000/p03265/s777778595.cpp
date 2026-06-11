#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int a[4];rep(i,4)cin>>a[i];
    
    cout<<a[2]+(a[1]-a[3])<<" "<<a[3]+(a[2]-a[0])<<" "<<a[0]+(a[1]-a[3])<<" "<<a[1]+(a[2]-a[0])<<endl;
	return 0;
}