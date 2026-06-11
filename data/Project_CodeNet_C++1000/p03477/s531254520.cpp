#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
	int a,b,c,d;cin>>a>>b>>c>>d;
  	if(a+b>c+d) cout<<"Left"<<endl;
  	else if(a+b==c+d) cout<<"Balanced"<<endl;
  	else cout<<"Right"<<endl;
}