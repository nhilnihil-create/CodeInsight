#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<(abs(a-b)<2?a+b:(max(a,b)*2)-1)<<endl;
}
