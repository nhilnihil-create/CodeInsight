#include <bits/stdc++.h>
using namespace std;


int main()
{
    int A,B;
    cin >> A >> B;
    vector<int> h(A);
    for(int i=0; i<A; i++)
    {
        cin >> h.at(i);
    }
    sort(h.begin(),h.end());
    int min=h.at(A-1);
    for(int i=0; i<A-B+1; i++)
    {
        if(min>h.at(B-1+i)-h.at(i))
        {
            min=h.at(B-1+i)-h.at(i);
        }
    }
    cout << min << endl;
}
