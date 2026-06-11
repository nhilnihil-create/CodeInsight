#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, a, x, index;
    double t;
    vector<double> v;
    cin >> n;
    cin >> t >> a;
    double arr[n];
    for(int i = 0; i < n; i++){
        cin >> x;
        arr[i] = t - (x * 0.006);
        v.push_back(abs(arr[i] - a));
    }
    index = min_element(v.begin(), v.end()) - v.begin();
    cout << index + 1;
}





///promy_pompom
//hello world
