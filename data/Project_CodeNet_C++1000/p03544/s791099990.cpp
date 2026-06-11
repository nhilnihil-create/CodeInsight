#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
    cin >> n;
    long long a,b,c;
    a=2;
    b=1;
    for(int i=0;i<n-1;i++){
    	c=a+b;
        a=b;
        b=c;
    }
    cout << b <<endl;
}
