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
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(a==b)
    {
        printf("%d", a+b);
    }
    else if(a>b)
    {
        printf("%d", 2*a-1);
    }
    else if(a<b)
    {
        printf("%d", 2*b-1);
    }
}
