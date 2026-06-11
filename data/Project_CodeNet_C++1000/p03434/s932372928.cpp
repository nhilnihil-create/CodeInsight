#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin >> n ;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t = 0 ,b = 0;a=0;
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=0; i--)
    {
        if(t==0)
        {
            a+= v[i];
           t = 1;
        }
        else
        {
            b += v[i];
            t = 0;
        }

    }
    cout << a-b << endl;

}
