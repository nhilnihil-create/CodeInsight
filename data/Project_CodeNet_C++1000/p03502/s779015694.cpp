#include <iostream>
using namespace std;

int main() {
    int n,tmp,h; cin>>n;
    tmp = n;
    h = 0;
    while(tmp>0){
        h+=tmp%10;
        tmp/=10;
    }
    if(n%h==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}