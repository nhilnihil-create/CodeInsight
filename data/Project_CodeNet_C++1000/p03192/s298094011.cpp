#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int ans=0;
    char a[5];
    cin>>a;
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='2') ans++;
    }
    cout<<ans<<endl;
    return 0;
}