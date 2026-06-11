#include<bits/stdc++.h>
using namespace std;

#define ll long long
int check_palindrome(string s)
{
    int j = 0;
    int l = s.size();
    for(int i=0; i<=l/2; i++)
    {
        if(s[i]!=s[l-i-1])
        {
            j=1;
        }
    }
    return j;
}

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    int cnt = 0;
    for(int i = a; i <= b; i++)
    {
        string s = to_string(i);
        if(!check_palindrome(s))
            cnt++;
    }
    cout << cnt;
    return 0;
}
