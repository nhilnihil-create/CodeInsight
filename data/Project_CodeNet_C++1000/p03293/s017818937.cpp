#include <iostream>
using namespace std;
int main(void){
    string s,t;
    cin>>s>>t;
    int l= s.size();
    for (int i = 0;i<l;i++){
        if (s==t.substr(i,l)+t.substr(0,i)){
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
    exit(0);
    
}
