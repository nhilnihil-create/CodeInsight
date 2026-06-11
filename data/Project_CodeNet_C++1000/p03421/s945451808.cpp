#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll n,a,b,m;
    cin>>n>>a>>b;
    if(n<a+b-1||n>b+a-1+(a-1)*(b-1)){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=b;i>1;i--){
        cout<<i<<" ";
    }
    cout<<1;
    m=n;
    while(m>b){
        int v=min(m-b, a-1);
        for(int i=0;i<v;i++){
            cout<<" "<<m-v+1+i;
        }
        m-=v;
    }
    
	return 0;
}