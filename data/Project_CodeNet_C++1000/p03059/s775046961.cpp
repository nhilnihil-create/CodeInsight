#include<bits/stdc++.h>

using namespace std;

int main(void){
    int A,B,T;
    cin>>A>>B>>T;
    int sum=0;
    for(int i=A;i<T+0.5;i+=A){
        sum+=B;
    }
    cout<<sum<<endl;
    return 0;
}
