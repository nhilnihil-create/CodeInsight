#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    double a,b,c,d;
    cin >> a >> b >> c >>d;
    if(abs(a-c)<=d){
        cout << "Yes" <<endl;
    }else if(abs(a-b)<=d&&abs(b-c)<=d){
        cout <<"Yes"<<endl;
    }else{
        cout <<"No"<<endl;
    }

    
    return 0;
}