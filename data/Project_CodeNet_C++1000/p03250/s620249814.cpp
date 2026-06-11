#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3],ans;
    for(int i=0;i<3;++i){
        cin>>a[i];
    }
    sort(a,a+3);
    ans=a[2]*10+a[1]+a[0];
    cout<<ans<<endl;
	return 0;
}