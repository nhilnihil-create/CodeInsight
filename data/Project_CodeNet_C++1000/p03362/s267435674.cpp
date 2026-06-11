#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    const int lim = 55555;
    vector<int> prime[lim];
    vector<int> ans;
    for(int i = 2; i < lim; i++)
{
    bool k = true;
    for(int j = 2; j <= sqrt(i); j++)
    {
        if(i % j == 0) k = false;
    }
    if(k && i%10 == 1) ans.push_back(i);
}
for(int i = 0; i < n; i++)
{
    cout << ans[i] << " ";
}
} 
