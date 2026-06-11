#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++){
    	cin >> x[i] >> y[i];
	}
    for(int i=0;i<n;i++){
    	if(abs((x[0] + y[0]) % 2) != abs((x[i] + y[i]) % 2)){
    		cout << -1 << endl; return 0;
		}
	}
    int par = (1==abs((x[0] + y[0]) % 2) ? 0 : 1);
    cout << 31 + par << endl;
    int p = 1;
    if(par) cout << 1 << " ";
    for(int i=0;i<31;i++){
  		cout << p << " ";
    	p = 2 * p;
  	}
   	cout << endl;
    for(int i=0;i<n;i++){
	 	p = 1073741824;
  	  	if(par) cout << "D";
		int xx = x[i], yy = y[i] + par;
    	char c[32]; c[31] = '\0';
   	    for(int j=0;j<31;j++){
      		int u = xx + yy, v = xx - yy;
      	  	if(u >=0 && v >= 0){
				c[30-j] ='R'; xx -= p;
			}else if(u >=0 && v <= 0){
			    c[30-j] ='U'; yy -= p;
			}else if(u <=0 && v <= 0){
				c[30-j] ='L'; xx += p;
			}else if(u <=0 && v >= 0){
      	    	c[30-j] ='D'; yy += p;
			}
	   		p /= 2;
      	}
      	cout << c << endl;
  	}
   	return 0;
}
