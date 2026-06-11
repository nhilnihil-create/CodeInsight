#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define inf 6000000000000000000
#define norm 0
#define mod 1000000007
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
int main()
{
    IO
    string arr[2];
    cin>>arr[0];
    cin>>arr[1];
    if(arr[0][0]==arr[1][2]&&arr[0][1]==arr[1][1]&&arr[0][2]==arr[1][0])
    {
        cout<<"YES";
    }
    else cout<<"NO"<<endl;
    return 0;
}


