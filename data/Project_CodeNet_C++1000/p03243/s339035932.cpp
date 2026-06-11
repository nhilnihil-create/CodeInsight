#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int a[9];
	int cnt=111;
	rep(i,9){
		a[i]=cnt;
		cnt+=111;
	}
	rep(i,9){
      if(n<=a[i]){
        cout << a[i] << endl;
		return 0; 
      }
    }
}