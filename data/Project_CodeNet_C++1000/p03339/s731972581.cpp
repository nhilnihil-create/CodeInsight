#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;

    int N, tmp;

    string list;
    cin >> N >> list;

    //一番右がリーダーのときの人数
    for (int i = 1; i < N; i++)
    {
        if(list.at(i)=='E')
            count++;
    }

    tmp = count;
    
    for (int i = 1; i < N;i++)
    {
        

        if(list.at(i)=='E')
            tmp--;
        if (list.at(i - 1) == 'W')
            tmp++;

        count = min(count,tmp);
    }

    cout << count;
}