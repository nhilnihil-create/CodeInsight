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
    int a, b, c, m;
    scanf("%d %d %d", &a, &b, &c);
    m = max(a,max(b, c));
    if(m==a)
    {
        printf("%d",(a*10)+b+c);
    }
    else if(m==b)
    {
        printf("%d", (b*10)+a+c);
    }
    else if(m==c)
    {
        printf("%d", (c*10)+a+b);
    }
}
