#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin>>N;
    int digit[3];
    for(int i=N;i<=999;i++){
        bool flag=false;
        string num=to_string(i);
        if(num[0]==num[1]&&num[1]==num[2]) flag=true;
        if(flag){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

