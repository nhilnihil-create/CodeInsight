#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    char c[n];
    int MIN=0,MAX=0,ne,po,pu=0,mai=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>=0){c[i]='+';pu++;}
        else {c[i]='-';mai++;}
        if(MIN>=a){
            MIN=a;
            ne=i+1;
        }
        if(MAX<=a){
            MAX=a;
            po=i+1;
        }
    }
    if(abs(MIN)<=abs(MAX)){
        cout<<n+mai<<endl;
        for(int i=0;i<n;i++){
            cout<<po<<" "<<i+1<<endl;
            if(c[i]=='-')cout<<po<<" "<<i+1<<endl;
            po=i+1;
        }
    }
    else{
        cout<<n+pu<<endl;
        for(int i=n;i>0;i--){
            cout<<ne<<" "<<i<<endl;
            if(c[i-1]=='+')cout<<ne<<" "<<i<<endl;
            ne=i;
        }
    }
}
