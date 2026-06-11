#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int N;cin>>N;
    string str="";
    while(N!=0){
        int r=N%2;
        if(r<0)r+=2;
        N=(N-r)/(-2);
        str+=(char)('0'+r);

    }
    reverse(str.begin(),str.end());
    if(str=="")str="0";
    cout<<str<<endl;
}