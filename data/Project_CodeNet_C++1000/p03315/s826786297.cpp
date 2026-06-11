#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<4;i++){
        if(s[i]=='+')ans++;
        else if(s[i]=='-')ans--;
    }
    cout<<ans<<endl;
    return 0;
}