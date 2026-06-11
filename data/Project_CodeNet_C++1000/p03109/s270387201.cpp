#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,m,d;
    char c;
    cin >> y >> c >> m >> c >>d;
     
    // cout << "y:" << y << endl;
    // cout << "m:" << m << endl;
    // cout << "d:" << d << endl;
    if(y<=2019&&m<=4){
        cout<<"Heisei"<<endl;
    }else if(y<=2018){
        cout<<"Heisei"<<endl;
    }else{
        cout<<"TBD"<<endl;
    }
}