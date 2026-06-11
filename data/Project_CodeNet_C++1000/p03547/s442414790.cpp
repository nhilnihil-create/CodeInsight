#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    char a,b;
    int c,d;
    cin>>a>>b;
    string s="ABCDEF";
    for(int i=0;i<6;i++){
        if(s[i]==a){
            c=i;
        }
        if(s[i]==b){
            d=i;
        }
    }
    if(c>d){
        cout<<">"<<endl;
    }
    else if(c<d){
        cout<<"<"<<endl;
    }
    else{
        cout<<"="<<endl;
    }
  return 0;
}