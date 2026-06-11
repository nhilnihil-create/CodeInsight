#include <iostream>
using namespace std;
int main(void){
    int n,r,b;
    r=0;b=0;
    string s;
    cin>>n>>s;
    for (int i =0;i<n;i++){
        r+=(s[i]=='R');
        b+=(s[i]=='B');
    }
    if (r>b){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    cout<<endl;
}
