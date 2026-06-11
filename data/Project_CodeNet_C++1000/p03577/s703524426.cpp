#include<bits/stdc++.h>
using namespace std;
string a;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>a;
    a.erase(a.length()-8,a.length()-1);
    cout<<a<<endl;
    return 0;
}