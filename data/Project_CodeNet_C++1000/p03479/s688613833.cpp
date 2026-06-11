#include<bits/stdc++.h>
using namespace std;

long long X,Y,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>X>>Y;
    while(X <= Y){
        X *= 2;
        ans++;
    }
    cout<<ans<<endl;
}
