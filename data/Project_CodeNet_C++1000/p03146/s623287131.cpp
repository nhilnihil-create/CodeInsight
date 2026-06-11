#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, sz1, sz2;
    cin >> n;
    vector<int> v, v1, v2;
    v.push_back(n);
    v1.push_back(n);
    while(1){
        sort(v1.begin(), v1.end());
        sz1 = v.size();
        sz2 = unique(v1.begin(), v1.end()) - v1.begin();
        if(sz2 < sz1){
            break;
        }
        else if(n % 2 == 0){
            n = n / 2;
            v.push_back(n);
            v1.push_back(n);
        }
        else{
            n = (3 * n) + 1;
            v.push_back(n);
            v1.push_back(n);
        }
    }
    cout << v.size();

}





///promy_pompom
//hello world
