#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int t=0,a,b,c,d,o=0,u=0;
    cin>>a>>b>>c>>d;
    if(a-b>0){
        if(a-b<=d){
            t=1;
        }
    }
    else if (a-b<=0){
            if(b-a<=d){
                t=1;
            }
    }
    if(b-c>0){
        if(b-c<=d){
            o=1;
        }
    }
    else if(b-c<=0){
        if(c-b<=d){
            o=1;
        }
    }
    if(a-c>0){
        if(a-c<=d){
            u=1;
        }
    }
    else if(a-c<=0){
        if(c-a<=d){
            u=1;
        }
    }
    if(u==1){
        cout<<"Yes"<<endl;
    }
    else if(t==1 && o==1){
            cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
}
