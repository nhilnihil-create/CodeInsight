#include <bits/stdc++.h>
using namespace std;

int k, even, odd;
int main()
{
    cin>>k;
    even = k/2;
    odd = k - even;
    cout<<even*odd<<endl;
}