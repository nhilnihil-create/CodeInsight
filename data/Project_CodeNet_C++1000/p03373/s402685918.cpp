#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  	int A, B, C, X, Y;
  	cin >> A >> B >> C >> X >> Y;
  	long long ans=A*X+B*Y;
  	int many = max(X, Y);
  	
  	for(int i=0;i<=many;i++){
      	long long pay=A*(X-i)+B*(Y-i)+C*2*i;
      	if(X-i<0) pay=B*(Y-i)+C*2*i;
      	if(Y-i<0) pay=A*(X-i)+C*2*i;
      	ans=min(pay, ans);
    }
  	cout << ans << endl;
}