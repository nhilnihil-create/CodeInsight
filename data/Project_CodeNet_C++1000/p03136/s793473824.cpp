#include <iostream>
#include<algorithm>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a;
    c=0;
    int S[a];
    for(int i=0;i<a;i++){
        cin>>S[i];
    }
    sort(S,S+a);
    b=S[a-1];
    for(int i=0;i<a-1;i++){
        c=c+S[i];
    }
    if(b<c){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    
    
}
