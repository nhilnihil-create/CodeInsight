#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 
 
int main(){
    int s;
    cin>>s;

    int a = s/100;
    int b = s%100;

    bool abmm=false;
    bool amm=false;
    bool bmm=false;

    // if(a==0 || b==0){
    //     cout<<"NA"<<endl;
    //     return 0;
    // }

    if(1<=a && a<=12){
        amm=true;
    }
    if(1<=b && b<=12){
        bmm=true;
    }

    if(amm==true && bmm==true){
        cout<<"AMBIGUOUS"<<endl;
    }else if(amm==true){
        cout<<"MMYY"<<endl;
    }else if(bmm==true){
        cout<<"YYMM"<<endl;
    }else{
        cout<<"NA"<<endl;
    }
}