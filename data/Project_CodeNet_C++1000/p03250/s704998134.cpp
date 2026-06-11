#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    vector<int> cal;
    cal.push_back(10*a+b+c);
    cal.push_back(10*a+c+b);
    cal.push_back(10*b+a+c);
    cal.push_back(10*b+c+a);
    cal.push_back(10*c+a+b);
    cal.push_back(10*c+b+a);
    sort(cal.begin(),cal.end());
    cout << cal[cal.size()-1] << endl;
}