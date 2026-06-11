#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
    int n, k, different = 0;
    cin >> n >> k;
    LLI tmp;
    unordered_map <LLI, LLI> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if( arr[tmp] == 0 )
            different++;
        arr[tmp]++;
    }
    if( different <= k )
        cout << 0;
    else{
        int sorted[arr.size()], i = 0;
        for(auto x: arr)
            sorted[i++] = x.second;
        sort(sorted,sorted+arr.size());
        int sum = 0;
        for(int i = 0; i < different - k; i++)
            sum += sorted[i];
        cout << sum;
    }
}