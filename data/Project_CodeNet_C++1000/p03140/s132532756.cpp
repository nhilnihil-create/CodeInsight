#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	string a,b,c; cin >> a >> b >> c;
	int ans=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i]&&b[i]==c[i]){
			continue;
		}
		else if(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]){
			ans++;
		}
		else{
			ans+=2;
		}
	}
	cout << ans << endl;
}