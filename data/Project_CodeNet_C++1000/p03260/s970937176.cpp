#include <bits/stdc++.h>

using namespace std;

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
const int mxA = 1e7;
int freq [mxA+1] ;
int pref [mxA+1];

int main()
{
    fast();
    int a ,b;
    cin >> a>>b;
    int z = a*b ;
    if((z*1)%2!=0) return cout <<"Yes",0;
    else if((z*2)%2!=0) return cout <<"Yes",0;
    else if((z*3)%2!=0) return  cout <<"Yes",0;
    cout << "No";
}
