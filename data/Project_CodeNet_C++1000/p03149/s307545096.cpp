#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool f=1;
    if(a!=1&&b!=1&&c!=1&&d!=1){
        f=0;
    }else if(a!=9&&b!=9&&c!=9&&d!=9){
        f=0;
    }else if(a!=7&&b!=7&&c!=7&&d!=7){
        f=0;
    }else if(a!=4&&b!=4&&c!=4&&d!=4){
        f=0;
    }
    cout << (f ? "YES" : "NO") << endl;
}