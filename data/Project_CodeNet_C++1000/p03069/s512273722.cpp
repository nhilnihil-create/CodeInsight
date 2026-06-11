#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

static const double pi = 3.141592653589793;

double Cos(double D)
{
    return cos(pi/180 * D);
}

int main()
{
    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<pair<int,int>> BW(N+1,make_pair(0,0));// 黒、白。BW[i+1] : s[i]までの黒と白の数
    for(int i=0;i<N;i++)
    {
        BW[i+1] = BW[i];
        if(s[i]=='#') BW[i+1].first++;
        if(s[i]=='.') BW[i+1].second++;
    }

    int min_change = 1e9;
    for(int i=0;i<N+1;i++)
    {
        min_change = min(min_change,BW[N].second-BW[i].second+BW[i].first);
    }

    cout << min_change << endl;

    return 0;
}