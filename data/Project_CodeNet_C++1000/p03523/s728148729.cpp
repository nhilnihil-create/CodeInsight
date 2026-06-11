#include<iostream>
#include<bitset>
using namespace std;
int main(){
    string a="AKIHABARA",s,c;
    cin>>s;
    for(int i=0;i<16;i++){
        bitset<4>b(i);
        c=a;
        for(int i=3;i>=0;i--)if(!b[i])c.erase(c.begin()+(i?2*i+2:0));
        if(s==c){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}