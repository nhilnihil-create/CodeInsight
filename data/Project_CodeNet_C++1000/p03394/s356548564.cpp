#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    int n;
    cin >> n;
    if(n == 3)
    {
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
    set<int> ans;
    ans.insert(2);
    ans.insert(3);
    ans.insert(4);
    ans.insert(9);

    if(n > 4)
    {
        int size = n - 4;
        int x = size / 8;
        int k = 2;
        while(x--)
        {
            ans.insert(6*k);
            ans.insert(6*k+2);
            ans.insert(6*k+3);
            ans.insert(6*k+4);
            ans.insert(6*k+6);
            ans.insert(6*k+8);
            ans.insert(6*k+9);
            ans.insert(6*k+10);
            k += 2;
        }
        int y = size % 8;
        if(y == 1) ans.insert(6);
        else if(y == 2)
        {
            ans.insert(8);
            ans.insert(10);
        }
        else if(y == 3)
        {
            ans.insert(6);
            ans.insert(8);
            ans.insert(10);
        }
        else if(y == 4)
        {
            ans.insert(6*k);
            ans.insert(6);
            ans.insert(8);
            ans.insert(10);
        }
        else if(y == 5)
        {
            ans.insert(6);
            ans.insert(8);
            ans.insert(10);
            ans.insert(6*k);
            ans.insert(6*k+6);
        }
        else if(y == 6)
        {
            ans.insert(6);
            ans.insert(8);
            ans.insert(10);
            ans.insert(6*k);
            ans.insert(6*k+2);
            ans.insert(6*k+4);
        }
        else if(y == 7)
        {
            ans.insert(6);
            ans.insert(8);
            ans.insert(10);
            ans.insert(6*k);
            ans.insert(6*k+3);
            ans.insert(6*k+6);
            ans.insert(6*k+9);
        }
    }
    for(auto itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}

