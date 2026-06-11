#include <iostream>

using namespace std;

int possible_solution(int n,int x)
{
    return max(x,n-x);
}

int solve(string s)
{
    int n = s.size();
    int ret = n;

    for(int i = 0; i < n-1; i++)
    {
        if(s[i] != s[i+1]) ret = min(ret,possible_solution(n,i+1));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>> s;

    int sol = solve(s);
    cout<< sol;

    return 0;
}
