#include <bits/stdc++.h>
 
using namespace std;
		
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a;
    cin>>n;
    cin>>a;
    if((n%500)>a){
    	cout<<"No";
	}
	else{
		cout<<"Yes";
	}
    return 0;
}