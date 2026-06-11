#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int count=0;
    if(abs(a-b)<=d) count++;
    if(abs(b-c)<=d) count++;
    if(abs(a-c)<=d) {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(count==2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

