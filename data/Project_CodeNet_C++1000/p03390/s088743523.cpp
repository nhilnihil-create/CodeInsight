#include <iostream>
using namespace std;
typedef long long ll;
ll Q,A,B;

int main(){
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> A >> B;
		if(A==B) cout << 2*A-2 << endl;
		else if(A==B+1) cout << 2*B-2 << endl;
		else if(B==A+1) cout << 2*A-2 << endl;
		else{
			ll l = 0,r = max(A,B);
			while(l+1<r){
				ll m = (l+r)/2;
				if(m*m<A*B) l = m;
				else r = m;
			}
			if(l*(l+1)<A*B) cout << 2*l-1 << endl;
			else cout << 2*l-2 << endl;
		}
	}
}