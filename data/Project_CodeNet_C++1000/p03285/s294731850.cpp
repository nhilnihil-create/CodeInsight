#include<bits/stdc++.h>
using namespace std;



int main(void){
    int N;
    cin>>N;
    bool flag=false;
    for(int i=0;i<=25;i++){
        for(int j=0;j<=14;j++){
            if(4*i+7*j==N){
                flag=true;
                break;
            }
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

