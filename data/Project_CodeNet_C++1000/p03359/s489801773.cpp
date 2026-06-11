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
    int a, b, c;
    scanf("%d %d", &a, &b);
    for(int i=1;i<=12;i++)
    {
        if(a==i)
        {
            if(a<=b)
            {
                printf("%d", i);
            }
            else if(a>b)
            {
                printf("%d", i-1);
            }
        }
    }
}
