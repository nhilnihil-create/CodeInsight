#include<iostream>
using namespace std;

int main(){
    int N;
    bool judge=false;
    cin>>N;
        for(int a=0;a<=N/4;++a){
            for(int b=0;b<=N/7;++b){
                    if(4*a+7*b==N){
                         judge=true;
                        break;
                    }

            }
        }
        if(judge==false){cout<<"No";
        }
            else{
                cout<<"Yes";
            }
}