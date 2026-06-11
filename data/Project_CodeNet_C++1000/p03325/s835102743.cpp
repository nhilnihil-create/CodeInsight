#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;

int main(){
   int n;
   ll res = 0;
  	cin >> n;
  	for(int i = 1; i <= n; i++){
  	 	int x; cin >> x;
  	 	if(x&1)continue;
  	 	int cnt = 0;
  	 	while(x > 0){
  	 	 	if(x&1)break;
  	 	 	cnt++;
  	 	 	x/=2;
  	 	}
  	 	res += cnt;
  	}
  	cout << res << endl;
   return 0;
}                  
