#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, K;
    cin >> n >> K;
    string s;
    cin >> s;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if(s[i]!=s[i-1])
        {
            v.push_back(i);
        }
    }
    int maxv = 0;
    for (int k = 0; k < v.size(); k++)
    {
        int x;
        if (s[v[k]] == '0')
        {
            x = (k+2*K<v.size()?v[k + 2 * K]:n) - v[k];
        }
        else
        {
            x = (k+2*K+1<v.size()?v[k + 2 * K + 1]:n) - v[k];
        }
        maxv = max(maxv, x);
    }
    cout << maxv << endl;
    return 0;
}