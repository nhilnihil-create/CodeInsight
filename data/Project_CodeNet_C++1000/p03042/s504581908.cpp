#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

int main() {
    int s;
    cin>>s;
    bool yymm=false,mmyy=false;
    int b=s%100, t=(s-b)/100;
    if(t>0&&t<=12)mmyy=true;
    if(b>0&&b<=12)yymm=true;

    if (yymm){
        if(mmyy)cout<<"AMBIGUOUS"<<endl;
        else cout<<"YYMM"<<endl;
    }else if(mmyy) cout<<"MMYY"<<endl;
    else cout<<"NA"<<endl;

    return 0;
}