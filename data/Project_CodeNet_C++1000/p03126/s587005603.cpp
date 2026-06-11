#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m; 
    vector<int> like(m);

    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int a;
            cin >> a;
            like.at(a-1)++; 
        }
    }

    int cnt=0;
    for(int j=0; j<m; j++){
        if(like.at(j) == n)
        cnt++;
    }
    cout<< cnt << endl;


    return 0;
}