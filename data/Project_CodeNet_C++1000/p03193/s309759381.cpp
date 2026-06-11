#include <iostream>
using namespace std;
typedef long long ll;
ll n,a,b,c,d,ans;
int main(void){
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>c>>d;
        if(a<=c&&b<=d){
            ans++;
        }
    }
    cout<<ans<<endl;
}
