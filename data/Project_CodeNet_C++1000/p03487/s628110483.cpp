#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long int LLI;

int main()
{
    int n;
    cin >> n;
    LLI tmp, ans = 0;
    unordered_map <LLI, LLI> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr[tmp]++;
    }
    for(auto x: arr)
    {
        if( x.first <= x.second )
            ans += x.second - x.first;
        else
            ans += x.second;
    }
    cout << ans;
}