#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char start[5]={'M','A','R','C','H'};
ll counter[5];
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		for(int i=0; i<5; i++){
			if(s[0]==start[i]){
				counter[i]++;
				break;
			}
		}
	}
	ll ret = 0;
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			for(int k=j+1; k<5; k++) ret+=counter[i]*counter[j]*counter[k];
		}
	}
	cout<<ret;
}