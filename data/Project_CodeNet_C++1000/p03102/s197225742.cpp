#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, m, c, cnt = 0, sum;
    cin >> n >> m >> c;
    int B[m], arr[m];
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    for(int i = 1; i <= n; i++){
        sum = 0;
        for(int j = 0; j < m; j++){
            cin >> arr[j];
            sum = sum + arr[j] * B[j];
        }
        sum = sum + c;
        if(sum > 0){
            cnt ++;
        }
    }
    cout << cnt;



}





///promy_pompom
//hello world
