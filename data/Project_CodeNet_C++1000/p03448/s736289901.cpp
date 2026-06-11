#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int genjiten;
    int count=0;
    for(int i=0;i<a+1;i++){
        for(int j=0;j<b+1;j++){
            for(int h=0;h<c+1;h++){
                genjiten=500*i+100*j+h*50;
                if(genjiten==x){
                    count+=1;

                }
                else{
                    int unko=0;
                }
            }
        }
    }
    cout<<count<<endl;
}