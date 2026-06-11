#include <iostream>
#include <cmath>

using namespace std;

int main(){
	unsigned long n, p;
	cin >> n >> p;

    unsigned long tmp = p;
	unsigned long k = (unsigned long)(sqrt(p));
    unsigned long* ord = new unsigned long[k];

    if(p == 1){
        cout << 1 << endl;
    }else if(n == 1){
    	cout << p << endl;
    }else{
    	ord[0] = 1;
        for(unsigned long i = 1; i < k; i++){
		    unsigned long cnt = 0;

        	if(p % (i+1) == 0){
        		while(p % (i+1) == 0){
        			cnt++;
        			p = p / (i + 1);
        		}
        		ord[i] = cnt;
        		p = tmp;

        	}else{
        		ord[i] = 0;
        	}
        }
    
	    unsigned long maximum = 1;

    	for(unsigned long j = 0; j < k; j++){
    		if(ord[j]>=n && j+1 > maximum) maximum = j+1;
    	}
    	cout << maximum << endl;
    }

}