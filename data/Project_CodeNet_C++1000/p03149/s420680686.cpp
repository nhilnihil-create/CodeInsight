#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    vector<int>a(4);
    int b=0,c=0,d=0,e=0;
    for(int i=0;i<4;i++){
        cin>>a[i];
        if(a[i]==1){
            b++;
        }else if(a[i]==4){
            c++;
        }else if(a[i]==7){
            d++;
        }else if(a[i]==9){
            e++;
        }
    }
    if(b*c*d*e==1&&b+c+d+e==4){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}