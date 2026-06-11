#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    int ans, temp;
    ans = 0;
    temp = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            temp++;           
        } else
        {
            ans += (temp / 2);
            temp = 1;
        }   
    }
    ans += (temp / 2);
    cout << ans << endl;
    return 0;
    
}