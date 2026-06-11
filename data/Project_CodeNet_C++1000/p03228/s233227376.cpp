#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,c;
int main(void){
    cin>>a>>b>>c;
    for(int i=0;i<c;i++){
        if(i%2==0){
            if(a%2==1)a--;
            b+=a/2;
            a-=a/2;
        }
        else{
            if(b%2==1)b--;
            a+=b/2;
            b-=b/2;
        }
    }
    cout<<a<<" "<<b<<endl;
}
