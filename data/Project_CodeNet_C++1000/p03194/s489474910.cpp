#include <bits/stdc++.h>
using namespace std;

int main(){
	long n,p,l=0,k=1;
  	bool ok=true;
	cin >> n >> p;
  	if(n>40) {
    	cout << 1 << endl;return 0; 
    }
  	vector<long> a(20);
  	vector<long> co(20);
  	a[0]=2;
  	while(p%2==0) {
    	co[0]++;
      	p/=2;
    }
  	long i;
  	for(i =3;i*i<=p;i+=2){
    	while(p%i==0) {
          	if(ok) {
				l++;
              	a[l] = i;
              	ok=false;
            }
            co[l]++;
          	p/=i;
        }
      	ok = true;
    }
  	if(p!=1) {
    	l++;
      	a[l] = p;
      	co[l] = 1;
    }
  	k = (long)pow(2.0, (int)(co[0] / n));
  	for(int j = 1; j<=l; j++) {
    	while(co[j] >= n) {
      		k *= a[j];
          	co[j] -= n;
        } 
	}
	cout << k;
}
