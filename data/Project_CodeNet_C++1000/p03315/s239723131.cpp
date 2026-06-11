#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int p=0,m=0;
    for(int i=0;i<4;++i){
        if(s[i]=='+')p++;
        else m--;
    }
    int ans=p+m;
    cout<<ans<<endl;
    return 0;
}