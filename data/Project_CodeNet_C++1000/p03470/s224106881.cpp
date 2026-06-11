#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    set<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        A.insert(temp);
    }
    cout << A.size() << endl;
    return 0;
}