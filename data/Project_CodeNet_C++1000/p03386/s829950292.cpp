#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main(){
	int a,b,k;
	cin>>a>>b>>k;
	for(int i = a; i <= b; i++){
		if(  a<= i && i < a+k ){
			cout<<i<<endl;
		}else if( b - k < i && i <= b){
			cout<<i<<endl;
		}
	}
	return 0;
}
