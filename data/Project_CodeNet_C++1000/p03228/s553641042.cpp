#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>
#include<map>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
	int a, b, k;cin>>a>>b>>k;
	for(int i=0;i<k;i++){
		if(i%2==0){
			a/=2;
			b+=a;
		}else{
			b/=2;
			a+=b;
		}
	}
	cout << a << " " << b << endl;
}