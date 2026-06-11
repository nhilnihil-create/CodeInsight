//
//  main.cpp
//  vjudge
//
//  Created by Sudipto Mondal on 7/9/20.
//  Copyright © 2020 Sudipto Mondal. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    long long int a,b,t;
    cin>>a>>b;
    t=(a*3)+b;
    if(t<2){
        cout<<0<<endl;
    }else {
        cout<<t/2<<endl;
    }
    return 0;
}
