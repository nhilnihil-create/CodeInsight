#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int w=0;
    int l = 0;
    int total = 15;

    for(int i=0;i<str.length();i++){
        if(str[i]=='o'){
            w++;
        }
        else{
            l++;
        }
    }
    int r = total-str.length();
    if((r+w)>=8){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
