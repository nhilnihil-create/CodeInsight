#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[3];
    for(int i=0;i<3;++i){
        a[i]=n%10;
        if(a[i]==9)a[i]=1;
        else if(a[i]==1)a[i]=9;
        n/=10;
    }
    for(int i=2;i>=0;--i)cout<<a[i];
    cout<<endl;

}
