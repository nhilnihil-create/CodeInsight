#include <iostream>

using namespace std;

int sum_dig(int a){
	int s = 0;
	for(int i = a; i > 0; i /= 10){
		s += i%10;
	}
	return s;
}

int main(){
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n;
    m = n;

    for(int a = n-2, b = 2; b <= n/2; a--, b++){
    	if(b == 2){
    		m = sum_dig(a)+sum_dig(b);
    		continue;
    	}
    	int t = sum_dig(a)+sum_dig(b);
    	if(t < m)
    		m = t;
    }

    cout<<m<<endl;

    return 0;
}