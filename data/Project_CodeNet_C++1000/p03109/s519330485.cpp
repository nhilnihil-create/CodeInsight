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
    int a, b, c;
    char temp;
    cin>>a>>temp>>b>>temp>>c;
    if(a>2019)
    {
        printf("TBD");
    }
    else if(a<=2019)
    {
        if(b<=4)
        {
            if(c<=30)
            {
                printf("Heisei");
            }
        }
        else if(b>4)
        {
            printf("TBD");
        }
    }
}
