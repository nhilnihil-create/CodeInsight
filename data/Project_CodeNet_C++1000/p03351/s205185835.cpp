#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d;
    e=a-c;
    if(e<0){
        e=-e;
    }
    f=a-b;
    if(f<0){
        f=-f;
    }
    g=b-c;
    if(g<0){
        g=-g;
    }
    if(e<=d){
        cout<<"Yes"<<endl;
    }
    else{
        if(f<=d&&g<=d){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
