#include<iostream>
using namespace std;

int main(){
    int a[114514];
    for(int i=0;i<4;i++){
        int x;
        cin>>x;
        
        a[x]++;
    }
    if(a[1]==1&&a[9]==1&&a[7]==1&&a[4]==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
