#include <iostream>
#include <vector>
using namespace std;

int nextTime(int t, int c, int s, int f)
{
    t = max(t,s);
    if(t%f != 0)
    {
        t = f*(t/f)+f;
    }
    return t+c;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n-1; ++i)
    {
        int c,s,f;
        cin >> c >> s >> f;
        for(int j = 0; j <= i; ++j)
        {
            vec[j] = nextTime(vec[j],c,s,f);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << vec[i] << endl;
    }
}