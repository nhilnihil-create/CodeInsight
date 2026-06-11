//
//  main.cpp
//  每个人都喜欢的食物
//
//  Created by 姚欣 on 2020/7/29.
//  Copyright © 2020 任奕霏. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int N,M,i,j,k;
    cin >> N >> M;
    int K[N],a[N][M],sum = 0,b = 0;
    for(i = 0; i < N; i ++)
    {
        for(j = 0; j < M; j ++)
            a[i][j] = 0;
    }
    for(i = 0; i < N; i ++)
    {
        cin >> K[i];
        for(j = 0; j < K[i]; j ++)
        {
            cin >> a[i][j];
        }
    }
    for(k = 1; k <= M; k ++)
    {
        for(i = 0; i < N; i ++)
        {
            for(j = 0; j < M; j ++)
            {
                if(a[i][j] == 0)
                    continue;
                if(a[i][j] == k)
                    sum ++;
            }
        }
        if(sum == N)
            b ++;
        sum = 0;
    }
    cout << b << endl;
    return 0;
}
