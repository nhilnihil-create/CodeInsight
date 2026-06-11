#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    cin>>n>>m;
    for(int i=m/n;i>=1;i--){
        if(m%i==0){
            int g=m/i;
            if(g>=n){
            	cout<<i<<endl;
            	return 0;
			}
        }
    }
    return 0;
}