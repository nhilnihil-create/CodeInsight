#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int n;
    int count=0;
    string s,ans;
    string a;
    cin>>n;
    cin>>s;
    for (int i=0; i<n; i++){
        a=s[i];
        if(a=="R"){
            count+=1;
        }
    }ans="Yes";
    if (n/2>=count){
        ans="No";
    }cout<<ans;
}
