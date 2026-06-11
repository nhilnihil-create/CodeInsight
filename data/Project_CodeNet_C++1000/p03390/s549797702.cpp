#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int i,q;
	cin >> q;
	for(i=0;i<q;i++){
		long long a,b,c,d,ans1,ans2;
		cin >> a >> b;
		if(a>b){
			long long x;
			x = a;
			a = b;
			b = x;
		}
		if(b-a==1 || a==b){
			cout << 2*(a-1) << endl;
		}else{
			long long l = -1,r = 1000000000,mid;
			while(r-l>1){
				mid = (l+r)/2;
				if(mid*mid>a*b){
					r = mid;
				}else{
					l = mid;
				}
			}
			c = l;
			l = -1; r = 1000000000;
			while(r-l>1){
				mid = (l+r)/2;
				if(mid*(mid+1)>a*b){
					r = mid;
				}else{
					l = mid;
				}
			}
			d = l;
			if(c*c==a*b){
				ans1 = 2*c-3;
			}else{
				ans1 = 2*c-2;
			}
			
			if(d*(d+1)==a*b){
				ans2 = 2*d-3;
			}else{
				ans2 = 2*d-1;
			}
			cout << max(ans1,ans2) << endl;
		}
	}
}