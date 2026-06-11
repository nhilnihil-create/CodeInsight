#include <bits/stdc++.h>
using namespace std;

int N,x;
int a[110];

int main(){
    cin>>N>>x;

    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }

    sort(a,a+N);
    
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];

      if(sum>x || (i==N-1 && sum < x)) break;

        ans++;
    }
    
    cout << ans << endl;
    

    return 0;
}
