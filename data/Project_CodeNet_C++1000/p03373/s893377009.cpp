//
//  main.cpp
//  project for C++
//
//  Created by 伊藤博隆 on 2020/04/17.
//  Copyright © 2020 伊藤博隆. All rights reserved.
//

#include <iostream>
#include<set>
#include<string>
#include <sstream>

using namespace std;
int A,B,C,X,Y;
int main(){
    cin >> A >> B >> C >> X >> Y ;
    if (X>=Y) {
         cout << min({A*X+B*Y, A*(X-Y)+2*C*Y, max(2*C*Y , 2*C*X)});
    }else{
   cout << min({A*X+B*Y, B*(Y-X)+2*C*X, max(2*C*Y , 2*C*X)});
    }
    return 0;
}


