#include<iostream>
using namespace std;
int main(){
    int N,ma=-1000001,mi=1000001,ma_idx=0,mi_idx=0;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(ma<a[i])ma=a[i],ma_idx=i;
        if(mi>a[i])mi=a[i],mi_idx=i;
    }
    cout<<2*N-2<<endl;
    for(int i=0;i<N;i++){
        if(i==(abs(mi)<=abs(ma)?ma_idx:mi_idx))continue;
        cout<<(abs(mi)<=abs(ma)?ma_idx:mi_idx)+1<<" "<<i+1<<endl;
    }
    for(int i=1;i<N;i++)cout<<(abs(mi)<=abs(ma)?i:N-i+1)<<" "<<(abs(mi)<=abs(ma)?i+1:N-i)<<endl;
    return 0;
}