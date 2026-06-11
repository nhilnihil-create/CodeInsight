#include<iostream>
#include<string>
using namespace std;
int main(){
    int N,i,j,t=0;
    cin>>N;
    string s[N];
    for(i=0;i<N;i++){
        cin>>s[i];
    }
    for(i=N-1;i>=1;i--){
        if(s[i][0]!=s[i-1][s[i-1].size()-1]){
            t=1;
            break;
        }
        for(j=i-1;j>=0;j--){
            if(s[i]==s[j]){
                t=1;
                break;
            }
        }
    }
    if(t==1){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    return 0;
}