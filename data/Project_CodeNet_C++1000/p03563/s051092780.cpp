#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>stk;

    int n;

    cin>>n;
    stk.push(n);

    cin>>n;

    stk.push(n);

        int k=stk.top();
        k=k*2;
        stk.pop();
        int m=stk.top();

        cout<<k-m<<endl;

}
