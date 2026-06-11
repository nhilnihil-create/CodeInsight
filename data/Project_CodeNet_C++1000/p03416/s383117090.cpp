#include<iostream>

using namespace std;

int main(){
    int A,B,count=0;
    cin>>A>>B;
        for(int i=A;i<=B;i++){
            int x=i%10;
            int y=i%100/10;
            int z=i%10000/1000;
            int w=i/10000;
            if(x==w&&y==z)count++;
        }
    cout<<count;
}