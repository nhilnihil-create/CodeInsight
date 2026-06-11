#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    string s;

    cout<<0<<endl;
    cin>>s;
    if(s=="Vacant"){
        return 0;
    }
    int low=0,high=n;
    string t="";
    while(t!="Vacant"){
        int mid=(high+low)/2;
        cout<<mid<<endl;
        cin>>t;
        if((mid&1)^(s==t)) low=mid;
        else high=mid;
    }

    return 0;
}