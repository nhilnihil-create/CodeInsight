#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool chk=true;
    vector<int> A(5);
    int k;
    for (int i = 0; i < 5; i++)
    {
        cin >> A.at(i);
    }
    cin >> k;
    for(int i=0; i<5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(k<abs(A.at(i)-A.at(j)))
            {
                chk=false;
            }
        }
    }
    if(chk)
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    
}
