#include<bits/stdc++.h>

using namespace std;

int main(){
    char x,y;
    cin>>x>>y;

    if(x-'A'>y-'A'){
        cout<<">"<<endl;
    }else if(x==y){
        cout<<"="<<endl;
    }else{
        cout<<"<"<<endl;
    }

}