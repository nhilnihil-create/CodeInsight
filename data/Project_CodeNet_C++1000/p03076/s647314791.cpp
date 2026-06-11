//
//  main.cpp
//  五个菜
//
//  Created by 姚欣 on 2020/7/29.
//  Copyright © 2020 任奕霏. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int a[5],i,b = 10,c,t = 0;
    for(i = 0; i < 5; i ++)
    {
        cin >> a[i];
        if(a[i] % 10 != 0)
        {
            t += (a[i] / 10 + 1) * 10;
            c = a[i] % 10;
            if(c < b)
                b = c;
        }
        else
            t += a[i];
    }
    t = t - 10 + b;
    cout << t << endl;
    return 0;
}
