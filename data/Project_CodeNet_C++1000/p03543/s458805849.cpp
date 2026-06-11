#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,n1,n2;
    cin>>n;
    n1=n%1000;
    n2=(n/10)*10;
    if(n1%111==0||n2%111==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
