#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define ll long long
#define f first
#define s second
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
int main()
{
    IO
    int x,y,x1,y1,addx,addy;
    cin>>x>>y>>x1>>y1;
    addx=x1-x;
    addy=y1-y;
    cout<<x1-addy<<" "<<y1+addx<<" "<<x-addy<<" "<<y+addx;
    return 0;
}