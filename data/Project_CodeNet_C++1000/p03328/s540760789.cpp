#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int a, b; cin >> a >> b;
  	int n = b - a;
  	int ans = ((n + 1) * n / 2) - n - a;
  	cout << ans << endl;
    return 0;
}