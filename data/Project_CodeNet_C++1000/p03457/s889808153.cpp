#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int>t(n+1);
    vector<int>x(n+1);
    vector<int>y(n+1);
    for(int i=0;i<n;i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        if (t[i]-t[i-1]<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])||((t[i] - t[i - 1]) - (abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i]))) % 2 == 1) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}