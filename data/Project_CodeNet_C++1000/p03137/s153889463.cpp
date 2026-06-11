#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    int ans;
    vector<int> x(m);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }

    if(n > m){
        ans = 0;
    }
    else{
        sort(x.begin(), x.end());

        vector<int> l(m-1);
        for (int i = 0; i < m-1; i++)
        {
            l[i] = x[i+1] - x[i];
        }
        sort(l.begin(), l.end());

        int sum = 0;
        for (int i = 0; i < n-1; i++)
        {
            sum += l[m-2-i];
        }

        ans = x[m-1] - x[0] - sum;
    }
    cout << ans << endl;
    

}