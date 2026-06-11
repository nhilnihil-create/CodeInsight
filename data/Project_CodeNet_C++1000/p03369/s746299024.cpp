#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;cin>>str;
    int ans=700;
    for(int i=0;i<3;++i){
        if(str[i]=='o')ans+=100;
    }
    cout<<ans<<endl;
	return 0;
}