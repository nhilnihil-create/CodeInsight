#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	int a,b,k,t=0;
	cin>>a>>b>>k;
	for(int i=0;i<k;i++){
		if(t==0){
			if(a%2==0){

			}else{
				a--;
			}
			a/=2;
			b+=a;
			t=1;
		}else{
			if(b%2==0){

			}else{
				b--;
			}
				b/=2;
				a+=b;
				t=0;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}

