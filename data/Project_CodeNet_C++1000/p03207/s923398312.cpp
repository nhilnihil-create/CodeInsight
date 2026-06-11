#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int d;
    cin>>d;
    vector<int> a(d);
    for(int i=0;i<d;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int c=0;
    for(int i=0;i<d-1;i++)
    {
        c+=a[i];
    }
    c+=(a[d-1]/2);
    cout<<c<<endl;
    return 0;
}
