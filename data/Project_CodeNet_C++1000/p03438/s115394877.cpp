#include<iostream>
using namespace std;
long long N,A,B;
int main(){
    cin>>N;
    int a[N],b[N];
    for(int i=0;i<N;i++)cin>>a[i];
    for(int i=0;i<N;i++)cin>>b[i];
    for(int i=0;i<N;i++){
        if(a[i]>b[i])A+=(a[i]-b[i]);
        if(a[i]<b[i])B+=(b[i]-a[i])/2;
    }
    cout<<(A<=B?"Yes":"No")<<endl;
    return 0;
}