#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[100100];


int main()
{

    int n,x;
    cin >> n >> x;
    vector<int>vec;
    int sum = 0,cnt = 0;
    int mn = INT_MAX;
    for(int i=1; i<=n; i++)
    {
        int b;cin >> b;
        sum+=b;cnt++;
        //vec.push_back(b);
         mn = min(mn,b);
    }

    int rest = x - sum;
    cnt += rest/mn;
    cout << cnt << endl;






}
