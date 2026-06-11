#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, k = 0;
    string s[200], a[100], b[100], w;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> w;
        s[i] = w;
        a[i] = w[w.size() - 1];
        b[i] = w[0];
    }


    for(int j = 0; j < n; j++)
    {
        for(int i = j+1; i < n; i++)
        {
            if(s[i] == s[j])
            {
                cout << "No";
                return 0;
            }
        }
    }

    int j = 0;
    for(int i = 1; i < n; i++)
    {
        if(b[i] != a[j])
            k++;
            j++;
    }

    if(k > 0)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}