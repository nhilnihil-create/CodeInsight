#include<iostream>
using namespace std;
int main()
{
    int n, m, c, a[100][100], b[100];
    cin >> n >> m >> c;
    for(int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        int s = 0;
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            s = s + a[i][j] * b[j];
        }
        if(s + c > 0)
            k++;
    }
    cout << k;
    return 0;

}
