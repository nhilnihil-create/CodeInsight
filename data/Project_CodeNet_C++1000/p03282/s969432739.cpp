#include <iostream>
using namespace std;
bool pd(int a,string s){
    if(s[a]!='1'){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    int a,k,l=0;
    string s;
    cin>>s>>k;
    k--;
    for(a=0;a<s.size();a++){
        if(pd(a,s)==false){
            if(a<=k){
                cout<<s[a];
                return 0;
            }
        }
    }
    cout<<1;
    return 0;
}