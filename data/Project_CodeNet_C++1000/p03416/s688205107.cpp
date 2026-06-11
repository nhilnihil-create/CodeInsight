#include<bits/stdc++.h>
using namespace std;
int palindrome(int n)
{
    int r=0;
    int temp=n;
    while(temp>0)
    {
        r=r*10+(temp%10);
        temp=temp/10;
    }
    if(r==n)
        return 1;
    else
        return 0;
}
int check_palindrome(int a, int b)
{
    int cnt=0;
    for(int i=a; i<=b; i++)
    {
        if  (palindrome(i)==1)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
int main()
{
    int a,b;
    cin >> a >> b;
    check_palindrome(a, b);
}
