#include<iostream>
using namespace std;

int main(){
    int A, B, total=0;
    float T;
    cin>>A>>B>>T;
    for (int i = A; i < T+0.5; i+=A)
    {
        /* code */
        total += B;
    }
    cout<<total<<endl;
    
}