#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int K;
    cin>>K;
    sort(a,a+3);
    int sum=0;
    for(int i=0;i<K;i++){
        a[2]*=2;
    }
    for(int i=0;i<3;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}

