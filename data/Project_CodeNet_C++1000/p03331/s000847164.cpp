#include<iostream>

using namespace std;

int main(){
    int N,i,sum=0;
    cin>>N;
        if(N%10!=0){
            i=N;
            while(i>0){
                sum+=i%10;
                i/=10;
            }
        cout<<sum;
        }else{
            cout<<"10";
        }

}