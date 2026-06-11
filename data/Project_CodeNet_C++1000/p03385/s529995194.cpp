#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;cin>>str;
    int a=0,b=0,c=0;
    for(int i=0;i<3;++i){
        if(str[i]=='a')a++;
        if(str[i]=='b')b++;
        if(str[i]=='c')c++;
    }
    int ans=a*b*c;
    if(ans==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

	return 0;
}