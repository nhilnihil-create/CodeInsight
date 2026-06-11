
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int N;
    cin >> N;
    int a[N];
    int count = 0;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = 0; i < N; i++)
    { 
         while (a[i]%2 == 0)
         {
            a[i] /=2;
            count++;
         }
      
    }

    cout << count;

    return 0;
}
