#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans=0;
    int i=0;
    while(1){
        i++;
        if(i*i<=n)ans=i*i;
        else break;
    }
    
    cout << ans;
    
	return 0;
}