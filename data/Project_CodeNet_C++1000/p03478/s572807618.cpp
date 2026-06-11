#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int a,b;cin>>a>>b;
    
    int ans = 0;
    for(int i = 1; i<=n;++i){
        int tmp = i;
        int tmp2 = 0;
        while(tmp > 0){
            int x = tmp%10;
            tmp2 += x;
            tmp/=10;
        }
//      cout<<tmp2<<endl;
        if(tmp2>=a && tmp2 <=b)ans+=i;
    }
    cout<<ans<<endl;
	return 0;
}