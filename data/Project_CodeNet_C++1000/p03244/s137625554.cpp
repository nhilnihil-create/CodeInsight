#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int getSecond(vector<pair<int,int>> vec, int def)
{
    if(vec.size() <= 1)
    {
        return def;
    }
    return vec[1].first;
}

int main()
{
    int n;
    cin >> n;
    map<int,int> odd;
    map<int,int> even;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if(i%2==0)
        {
            even[t] += 1;
        }
        else
        {
            odd[t] += 1;
        }
    }

    vector<pair<int,int>> oddPair;
    for(pair<int,int> p: odd)
    {
        oddPair.push_back(make_pair(p.second,p.first));
    }
    sort(oddPair.begin(), oddPair.end(), greater<pair<int,int>>());
    vector<pair<int,int>> evenPair;
    for(pair<int,int> p: even)
    {
        evenPair.push_back(make_pair(p.second,p.first));
    }
    sort(evenPair.begin(), evenPair.end(), greater<pair<int,int>>());

    int oddCnt = n/2;
    int evenCnt = n/2;
    if(oddPair[0].second != evenPair[0].second)
    {
        oddCnt = oddPair[0].first;
        evenCnt = evenPair[0].first;
    }
    else
    {
        int oddT = getSecond(oddPair, 0);
        int evenT = getSecond(evenPair, 0);
        if(oddT < evenT)
        {
            oddCnt = oddPair[0].first;
            evenCnt = evenT;
        }
        else
        {
            oddCnt = oddT;
            evenCnt = evenPair[0].first;
        }
        
    }
    cout << n - oddCnt - evenCnt << endl;
}