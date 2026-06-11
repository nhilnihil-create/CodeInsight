#include<bits/stdc++.h>
using namespace std;
#define Mod(n) n % 1000000007
const int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int main()
{    
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    int maxx = -101,miny = 101;
    int tmp;
    for(int i = 0;i < N;i++)
    {
        cin >> tmp;
        maxx = max(maxx,tmp);
    }
    
    for(int i = 0;i < M;i++)
    {
        cin >> tmp;
        miny = min(miny,tmp);
    }

    bool is = false;
    for(int i = X + 1;i <= Y;i++)
    {
        if(maxx < i && i <= miny)
            is = true;
    }
    cout << (is ? "No War\n" : "War\n");
}

