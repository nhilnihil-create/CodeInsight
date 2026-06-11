#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    long long int sum=0,count=0;
    int i;
    string s;
    cin >> s;
    for(i=s.size(); i>0; i--)
    {
        if(s[i-1]=='W')
            count++;
        if(s[i-1]=='B')
            sum+=count;
    }
    cout << sum;
    return 0;

}
