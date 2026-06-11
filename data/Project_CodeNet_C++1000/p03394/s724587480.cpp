#include <iostream>
#include <vector>
using namespace std;
int g(int a, int b){
    if(a%b==0)return b;
    return g(b, a%b);
}
int main(void){
    int n;
    vector<int> v;
    cin>>n;
    v.push_back(2);
    v.push_back(3);

    if(n==3){
        v.push_back(25);
    }else{
        v.push_back(4);
        v.push_back(9);
        int m=4,e=8,t=15,z=6;
        while(m<n){
            bool f=true;
            if(m<n-1&&e+2<30000){
                v.push_back(e);
                v.push_back(e+2);
                e+=6;
                m+=2;
                f=false;
            }
            if(m<n-1&&t+6<30000){
                v.push_back(t);
                v.push_back(t+6);
                t+=12;
                m+=2;
                f=false;
            }
            if(f){
                v.push_back(z);
                z+=6;
                m++;
            }
        }
    }




    for(int i=0;i<n;i++){
        cout<<v[i];
        if(i<n-1)cout<<" ";
    }
    cout<<endl;
}
