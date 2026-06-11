#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[100100];


int main()
{

    int n=700;
    int cnt = 0;
    string s;
    cin >> s;
    for(int i=0; i<3; i++)
    {
        if(s[i]=='o')cnt++;
    }

    cout << n+cnt*100 << endl;
}
