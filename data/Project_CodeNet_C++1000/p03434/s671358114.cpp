#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n ; cin>> n;
    vector<int>arr(n);
    for(int&p:arr)cin >> p ;
    sort(arr.rbegin(),arr.rend());
    int a = 0 , b = 0 ;
    for(int i = 0 ; i < n ; i++)   
    {
        if(i%2==0) a += arr[i];
        else b += arr[i];
    }
    cout << a - b ;
    return 0 ;
}