#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int lw[n],lb[n],rw[n],rb[n];
    lw[0]=0;
    lb[0]=0;
    rw[n-1]=0;
    rb[n-1]=0;
    for(int i=1;i<n;i++){
        if(s[i-1]=='.'){
            lb[i]=lb[i-1];
            lw[i]=lw[i-1]+1;
        }else{
            lb[i]=lb[i-1]+1;
            lw[i]=lw[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i+1]=='.'){
            rb[i]=rb[i+1];
            rw[i]=rw[i+1]+1;
        }else{
            rb[i]=rb[i+1]+1;
            rw[i]=rw[i+1];
        }
    }
    int min=1000000;
    for(int i=0;i<n;i++){
        if(s[i]=='.'){
            int mi=rw[i]<rb[i]?lb[i]+rw[i]:lb[i]+rb[i];
            min=min<mi?min:mi;
        }else{
            int mi=lw[i]<lb[i]?lw[i]+rw[i]:lb[i]+rw[i];
            min=min<mi?min:mi;
        }
    }
    cout<<min<<endl;
    return 0;
}