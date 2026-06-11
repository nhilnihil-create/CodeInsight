//
//  main.cpp
//  usaco
//
//  Created by 김현수 on 2020/08/30.
//  Copyright © 2020 김현수. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int a;
    scanf("%d", &a);
    if(a%2==0)
    {
        printf("%d", a);
    }
    else if(a%2!=0)
    {
        printf("%d", a*2);
    }
}
