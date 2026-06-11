#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, m, k, c = 0, a;
    cin >> n >> m;
    int arr[m+1] = {0};
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> a;
            arr[a]++;
        }
    }
    for(int i = 1; i < m+1; i++){
        if(arr[i] == n){
            c++;
        }
    }
    cout << c;

}





///promy_pompom
//hello world
