//
//  main.cpp
//  词语接龙
//
//  Created by 姚欣 on 2020/7/28.
//  Copyright © 2020 任奕霏. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int n,i,j,judge = 0;
    cin >> n;
    string s[n];
    for(i = 0; i < n; i ++)
        cin >> s[i];
    for(i = 1; i < n; i ++)
    {
        if(s[i][0] == s[i - 1][s[i - 1].size() - 1])
            judge ++;
        else
        {
            judge = 0;
        }
        for(j = 0; j < n; j ++)
        {
            if(j == i)
                continue;
            if(s[j] == s[i])
            {
                judge = 0;
                break;
            }
        }
        if(judge == 0)
        {
            cout << "No" << endl;
            break;
        }
    }
    if(judge != 0)
        cout << "Yes" << endl;
    return 0;
}
