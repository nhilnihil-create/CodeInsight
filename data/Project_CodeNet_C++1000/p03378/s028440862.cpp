#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n , m , x ; cin >> n >> m >> x ;
    vector<int>arr(m);
    for(int&p:arr) cin >> p ;
    // sort(arr.begin(),arr.end());
    int j = 0 , sum1 = 0 , sum2 = 0;
    for(int i = 0 ; i < m  ; i++)
    {
        if(arr[i]<x) 
        {
            sum1++; 
        }
        else 
        {
            sum2++;
        }
    }
    cout << min(sum1,sum2);
    return 0 ;
}