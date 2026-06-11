#include <iostream>

using namespace std;

int main(){
	long long i,j,k,n,a,b;
	cin >> n >> a >> b;
	if(a+b>n+1 || a*b<n){
		cout << -1 << endl;
	}else if(a==1){
		for(i=n;i>0;i--){
			cout << i << " ";
			}
	}else if(b==1){
		for(i=1;i<=n;i++){
			cout << i << " ";
		}
	}else{
		for(i=a;i>0;i--){
			cout << n+1-i << " ";
		}
		int m = (n-a)/(b-1);
		if((n-a)%(b-1)==0){
			for(j=1;j<=b-1;j++){
				for(k=0;k<m;k++){
					cout << n+1-a+k-j*m<< " ";
				}
			}
		}else{
			m++;
			int l = (n-a)%(b-1);
			for(j=1;j<=l;j++){
				for(k=0;k<m;k++){
					cout << n+1-a+k-j*m << " ";
				}
			}
			m--;
			for(j=1;j<=b-1-l;j++){
				for(k=0;k<m;k++){
					cout << n+1-a-l*(m+1)+k-j*m <<" ";
				}
			}
		}
	}
}
			