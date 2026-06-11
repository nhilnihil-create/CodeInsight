#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#define endl '\n'
using namespace std;
int main()
{
    int a,b,cnt=0;
    cin >> a >> b;
    while(a<=b)
    {
        if(to_string(a).at(0)==to_string(a).at(4))
            if(to_string(a).at(1)==to_string(a).at(3))cnt++;
        a++;
    }
    cout << cnt << endl;
    return 0;
}
