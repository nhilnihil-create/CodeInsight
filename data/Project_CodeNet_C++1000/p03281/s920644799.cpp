#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int answer = 0;

    for(int c = 1; c <= N; c+= 2)
    {
        int numofdivisors = 0;
        for (int X = 1; X <= c; ++X)
        {
            if(c % X == 0)
            {
                ++numofdivisors;
            }
        }
        if (numofdivisors == 8)
        {
            answer++;
        }
    }
    cout << answer << endl;
}