#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL x,y,ans=0;

int main() {
	cin>>x>>y;
    LL bil=x;
    while(bil<=y){
        ans++;
        bil*=2;
    }
    cout<<ans<<endl;
}
