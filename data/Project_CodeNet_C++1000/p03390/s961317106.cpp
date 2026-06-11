#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int q;
LL A,B;
int main() {
    cin>>q;
    while(q--){
        cin>>A>>B;
        LL x=sqrt(A*B-1);
        x=max(x-2,0LL);
        while((x+1)*(x+1)<A*B) ++x;
        if(A>B)swap(A,B);
        if(B-A<=1){
            printf("%d\n", 2*A-2); continue;
        }
        LL ans=2*x;
        if(x*(x+1) < A*B)ans--;
        else ans-=2;
        cout<<ans<<endl;
    }
}