/** 
 *  Author : Parth Prajapati
 * 	Institute : Pandit Deendayal Petroleum University
**/
#include<bits/stdc++.h>

using namespace std; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(n%k) cout<<1;
    else    cout<<0;
    return 0;
}