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
    int a, b;
    scanf("%d %d", &a, &b);
    if((a*b)%2!=0)
    {
        printf("Yes");
    }
    else if((a*b)%2==0)
    {
        printf("No");
    }
}
