#include<iostream>
#include<string>

using namespace std;

int main(){
    int N,r=0,b=0;
    string S;
    cin>>N>>S;

    for(int i=0;i<N;i++){
        if(S[i]=='R'){
            r++;
        }else{b++;}
    }
    if(r>b){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}